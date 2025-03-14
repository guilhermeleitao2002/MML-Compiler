#ifndef __MML_TARGETS_POSTFIX_WRITER_H__
#define __MML_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"
#include "targets/symbol.h"
#include <cdk/symbol_table.h>
#include <cdk/emitters/basic_postfix_emitter.h>
#include <set>
#include <stack>

#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace mml {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<mml::symbol> &_symtab;

    std::set<std::string> _functions_to_declare;

    bool _errors;

    cdk::basic_postfix_emitter &_pf;
    std::shared_ptr<mml::symbol> _function; // for keeping track of the current function and its arguments
    int _lbl;

    int _offset; // current framepointer offset (0 means no vars defined)

    std::stack<int> _whileCond, _whileEnd;

    bool _inFunctionBody;

    cdk::typename_type _lvalueType;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<mml::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _errors(false), _pf(pf), _function(nullptr), _lbl(0), _offset(0), _inFunctionBody(false), _lvalueType(cdk::TYPE_VOID) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

    void error(int lineno, std::string s) {
      std::cerr << "error: " << lineno << ": " << s << std::endl;
    }

  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // mml

#endif
