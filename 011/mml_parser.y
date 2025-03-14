%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	     /* integer value */
  double                d;	     /* double value */
  std::string          *s;	     /* symbol name or string literal */
  cdk::basic_node      *node;	     /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  mml::block_node      *blk;
  std::vector<std::shared_ptr<cdk::basic_type>> *funcs;
};

%token <i> tINTEGER
%token <d> tREAL
%token <s> tIDENTIFIER tSTRING
%token tWHILE tIF tPRINT tPRINTLN tREAD tBEGIN tEND tSIZEOF tNULL tINPUT tRETURN tSTOP tNEXT tARROW
%token tTYPE_STRING tTYPE_INT tTYPE_REAL tTYPE_AUTO tTYPE_VOID
%token tPUBLIC tFOREIGN tFORWARD

%nonassoc '(' ')' '[' ']'
%nonassoc tIF
%nonassoc tELSE tIFX

%right '='
%left tAND tOR
%right tNOT
%left tEQ tNE
%left '>' '<' tGE tLE
%left '+' '-'
%left '*' '/' '%'
%right tUNARY

%type <node> stmt  return vardec iffalse var
%type <sequence> list vardecs file exprs vars
%type <expression> expr call definition
%type <lvalue> lval
%type <type> data_type func_type
%type <s> string
%type <blk> block
%type <funcs> var_types output_type

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}

%%

file : vardecs tBEGIN vardecs list tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, $3, $4), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), $1)); }
     | vardecs tBEGIN vardecs      tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, $3, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), $1)); }
     | vardecs tBEGIN         list tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, $3), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), $1)); }
     | vardecs tBEGIN              tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true)), $1)); }
     | vardecs                                              { compiler->ast($$ = new cdk::sequence_node(LINE, $1)); }
     |         tBEGIN vardecs list tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, $2, $3), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
     |         tBEGIN vardecs      tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, $2, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
     |         tBEGIN         list tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, $2), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
     |         tBEGIN              tEND                     { compiler->ast($$ = new cdk::sequence_node(LINE, new mml::function_definition_node(LINE, nullptr, new mml::block_node(LINE, nullptr, nullptr), cdk::primitive_type::create(4, cdk::TYPE_INT), true))); }
     | /* empty */                                          { compiler->ast($$ = new cdk::sequence_node(LINE)); }
     ;

list :      stmt                                            { $$ = new cdk::sequence_node(LINE, $1); }
     | list stmt                                            { $$ = new cdk::sequence_node(LINE, $2, $1); }
     ;

stmt : expr ';'                                             { $$ = new mml::evaluation_node(LINE, $1); }
     | exprs tPRINT                                         { $$ = new mml::print_node(LINE, $1); }
     | exprs tPRINTLN                                       { $$ = new mml::print_node(LINE, $1, true); }
     | tSTOP tINTEGER ';'                                   { $$ = new mml::stop_node(LINE, $2); }
     | tSTOP          ';'                                   { $$ = new mml::stop_node(LINE, 0); } // FIXME: maybe 1 (instead of 0) is better?
     | tNEXT tINTEGER ';'                                   { $$ = new mml::next_node(LINE, $2); }
     | tNEXT          ';'                                   { $$ = new mml::next_node(LINE, 1); } // FIXME: maybe 0 (instead of 1) is better?
     | return                                               { $$ = $1; }
     | tIF '(' expr ')' stmt                                { $$ = new mml::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt iffalse                        { $$ = new mml::if_else_node(LINE, $3, $5, $6); }
     | tWHILE '(' expr ')' stmt                             { $$ = new mml::while_node(LINE, $3, $5); }
     | block                                                { $$ = $1; }
     ;
     
iffalse   : tELSE stmt                                      { $$ = $2; }
          | tIFX '(' expr ')' stmt                          { $$ = new mml::if_node(LINE, $3, $5); }
          | tIFX '(' expr ')' stmt iffalse                  { $$ = new mml::if_else_node(LINE, $3, $5, $6); }
          ;

expr : '(' expr ')'                                         { $$ = $2; }
     | '[' expr ']'                                         { $$ = new mml::stack_alloc_node(LINE, $2); }
     | '+' expr %prec tUNARY                                { $$ = new mml::identity_node(LINE, $2); }
     | '-' expr %prec tUNARY                                { $$ = new cdk::neg_node(LINE, $2); }
     | lval '?' %prec tUNARY                                { $$ = new mml::address_of_node(LINE, $1); }
     | expr '*' expr	                                   { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	                                   { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	                                   { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '+' expr	                                   { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	                                   { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '<' expr	                                   { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	                                   { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tLE expr                                        { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tGE expr	                                   { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tEQ expr	                                   { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr tNE expr	                                   { $$ = new cdk::ne_node(LINE, $1, $3); }
     | tNOT expr                                            { $$ = new cdk::not_node(LINE, $2); }
     | expr tAND expr                                       { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr tOR expr                                        { $$ = new cdk::or_node(LINE, $1, $3); }
     | lval '=' expr                                        { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | tINTEGER                                             { $$ = new cdk::integer_node(LINE, $1); }
     | tREAL                                                { $$ = new cdk::double_node(LINE, $1); }
     | string                                               { $$ = new cdk::string_node(LINE, $1); }
     | tNULL                                                { $$ = new mml::null_node(LINE); }
     | tSIZEOF '(' expr ')'                                 { $$ = new mml::sizeof_node(LINE, $3); }
     | tINPUT                                               { $$ = new mml::input_node(LINE); }
     | lval                                                 { $$ = new cdk::rvalue_node(LINE, $1); }  //FIXME
     | definition                                           { $$ = $1; }
     | call                                                 { $$ = $1; }
     ;

exprs     :           expr                                  { $$ = new cdk::sequence_node(LINE, $1); }
          | exprs ',' expr                                  { $$ = new cdk::sequence_node(LINE, $3, $1); }
          ;

vardec    : tFOREIGN data_type tIDENTIFIER '=' expr ';'     { $$ = new mml::variable_declaration_node(LINE, tFOREIGN,  $2, *$3, $5); }
          | tFOREIGN data_type tIDENTIFIER          ';'     { $$ = new mml::variable_declaration_node(LINE, tFOREIGN,  $2, *$3, nullptr); }
          | tFORWARD data_type tIDENTIFIER          ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); }
          | tPUBLIC  data_type tIDENTIFIER '=' expr ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, $5); }
          | tPUBLIC  data_type tIDENTIFIER          ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, nullptr); }
          | tPUBLIC            tIDENTIFIER '=' expr ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(0, cdk::TYPE_UNSPEC), *$2, $4); }
          |          data_type tIDENTIFIER '=' expr ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC, $1, *$2, $4); } // FIXME: this should be "private" somehow
          |          data_type tIDENTIFIER          ';'     { $$ = new mml::variable_declaration_node(LINE, tPUBLIC, $1, *$2, nullptr); } // FIXME: this should be "private" somehow
          ;

vardecs   :         vardec                                  { $$ = new cdk::sequence_node(LINE, $1); }
          | vardecs vardec                                  { $$ = new cdk::sequence_node(LINE, $2, $1); }
          ;

data_type : tTYPE_INT                                       { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
          | tTYPE_REAL                                      { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
          | tTYPE_STRING                                    { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
          | tTYPE_VOID                                      { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
          | tTYPE_AUTO                                      { $$ = cdk::primitive_type::create(0, cdk::TYPE_UNSPEC); }
          | '[' data_type ']'                               { $$ = cdk::reference_type::create(4, $2); }
          | func_type                                       { $$ = $1; }
          ;

func_type : output_type '<' var_types '>'                   { $$ = cdk::functional_type::create(*$3, *$1); }
          | output_type '<'           '>'                   { $$ = cdk::functional_type::create(std::vector<std::shared_ptr<cdk::basic_type>>(), *$1); }
          ;

output_type    : data_type                                  { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$ -> push_back($1); }
               ;

var_types :               data_type                         { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$ -> push_back($1); }
          | var_types ',' data_type                         { $$ = $1; $$ -> push_back($3); }
          ;

lval : tIDENTIFIER                                          { $$ = new cdk::variable_node(LINE, $1); }
     | expr '[' expr ']'                                    { $$ = new mml::index_node(LINE, $1, $3); }
     ;

return    : tRETURN      ';'                                { $$ = new mml::return_node(LINE, nullptr); }
          | tRETURN expr ';'                                { $$ = new mml::return_node(LINE, $2); }
          ;

block     : '{' vardecs list '}'                            { $$ = new mml::block_node(LINE, $2, $3); }
          | '{'         list '}'                            { $$ = new mml::block_node(LINE, nullptr, $2); }
          | '{' vardecs      '}'                            { $$ = new mml::block_node(LINE, nullptr, $2); }
          | '{'              '}'                            { $$ = new mml::block_node(LINE, nullptr, nullptr); }
          ;

call : expr '(' exprs ')'                                   { $$ = new mml::function_call_node(LINE, $1, $3); }
     | expr '('       ')'                                   { $$ = new mml::function_call_node(LINE, $1, nullptr); }
     | '@'  '(' exprs ')'                                   { $$ = new mml::function_call_node(LINE, nullptr, $3); }
     | '@'  '('       ')'                                   { $$ = new mml::function_call_node(LINE, nullptr, nullptr); }
     ;

definition     : '(' vars ')' tARROW data_type block        { $$ = new mml::function_definition_node(LINE, $2, $6, $5); }
               | '('      ')' tARROW data_type block        { $$ = new mml::function_definition_node(LINE, nullptr, $5, $4); }
               ;

vars :          var                                         { $$ = new cdk::sequence_node(LINE, $1); }
     | vars ',' var                                         { $$ = new cdk::sequence_node(LINE, $3, $1); }
     ;

var  : data_type tIDENTIFIER                                { $$ = new mml::variable_declaration_node(LINE, tPUBLIC, $1, *$2, nullptr); } // FIXME: this should be "private" somehow
     ;

string    :        tSTRING                                  { $$ = $1; }
          | string tSTRING                                  { $$ = $1; $$ -> append(*$2); delete $2; }
          ;

%%
