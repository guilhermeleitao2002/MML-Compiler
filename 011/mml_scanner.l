%option c++ prefix="mml_scanner_" outfile="mml_scanner.cpp"
%option stack noyywrap yylineno 8bit debug

%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "mml_parser.tab.h"

// output stream for building string literals
std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}

%x X_STRING X_BACKSLASH X_COMMENT

%%

yydebug=1; set_debug(1);

  /* ====================================================================== */
  /* ====[                         COMMENTS                           ]==== */
  /* ====================================================================== */

"//".*$                               std::cout << yylineno << ": ";

"/*"                                  yy_push_state(X_COMMENT);
<X_COMMENT>"/*"                       yy_push_state(X_COMMENT);
<X_COMMENT>"*/"                       yy_pop_state();
<X_COMMENT>.|\n                       ; 


  /* ====================================================================== */
  /* ====[                   Operadores de expressões                 ]==== */
  /* ====================================================================== */

">="                                  return tGE; 
"<="                                  return tLE;
"=="                                  return tEQ; 
"!="                                  return tNE;
"~"                                   return tNOT;
"&&"                                  return tAND;
"||"                                  return tOR;


  /* ====================================================================== */
  /* ====[                    Palavras reservadas                     ]==== */
  /* ====================================================================== */

"while"                               return tWHILE; 
"if"                                  return tIF;
"elif"                                return tIFX;
"else"                                return tELSE; 
"!"                                   return tPRINT;
"!!"                                  return tPRINTLN;
"begin"                               return tBEGIN; 
"end"                                 return tEND; 
"sizeof"                              return tSIZEOF; 
"null"                                return tNULL;
"input"                               return tINPUT;
"return"                              return tRETURN;
"stop"                                return tSTOP;
"next"                                return tNEXT;
"->"                                  return tARROW;


  /* ====================================================================== */
  /* ====[                      Símbolos Globais                      ]==== */
  /* ====================================================================== */

"foreign"                             return tFOREIGN;
"forward"                             return tFORWARD;
"public"                              return tPUBLIC;


  /* ====================================================================== */
  /* ====[                      Tipos de dados                        ]==== */
  /* ====================================================================== */

"auto"                                return tTYPE_AUTO;
"int"                                 return tTYPE_INT;
"double"                              return tTYPE_REAL;
"string"                              return tTYPE_STRING;
"void"                                return tTYPE_VOID;


  /* ====================================================================== */
  /* ====[                      Identificadores                       ]==== */
  /* ====================================================================== */

[A-Za-z][A-Za-z0-9]*                  yylval.s = new std::string(yytext); return tIDENTIFIER;


  /* ====================================================================== */
  /* ====[                  Cadeias de caracteres                     ]==== */
  /* ====================================================================== */

\"                                    yy_push_state(X_STRING);
<X_STRING>\\                          yy_push_state(X_BACKSLASH);
<X_STRING>\"                          {
                                        yylval.s = new std::string(strlit.str());
                                        strlit.str("");
                                        yy_pop_state();
                                        return tSTRING;
                                      }
<X_STRING>.                           strlit << *yytext;

<X_BACKSLASH>n                        strlit << '\n'; yy_pop_state();
<X_BACKSLASH>r                        strlit << '\r'; yy_pop_state();
<X_BACKSLASH>t                        strlit << '\t'; yy_pop_state();
<X_BACKSLASH>\\                       strlit << '\\'; yy_pop_state();

<X_BACKSLASH>[0-7]{1,3}               {
                                        strlit << (char)(unsigned char)strtoul(yytext, NULL, 8);
                                        yy_pop_state();
                                      }
<X_BACKSLASH>.                        strlit << *yytext; yy_pop_state();


  /* ====================================================================== */
  /* ====[                      Números inteiros                      ]==== */
  /* ====================================================================== */

0[0-7]+                               try { yylval.i = std::stoi(yytext, nullptr, 8); return tINTEGER; } catch(std::out_of_range const&) { yyerror("Error : Overflow detected"); }
0[0-9]+                               yyerror("Error : Invalid octal number.");

[0-9]+                                try { yylval.i = std::stoi(yytext, nullptr, 10); return tINTEGER; } catch(std::out_of_range const&) { yyerror("Error : Overflow detected"); }

  /* ================================================================ */
  /* ====[                      Real Numbers                    ]==== */
  /* ================================================================ */
  
([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?   { yylval.d = strtod(yytext, NULL); if(errno == ERANGE) yyerror("Error : Overflow detected"); return tREAL; }


  /* ====================================================================== */
  /* ====[                            Outros                          ]==== */
  /* ====================================================================== */

[-()<>=+*/%;{},\[\]?@]                return *yytext;
[ \r\t\n]                             ; /* ignore whitespace */


.                                     yyerror("Unknown character");

%%