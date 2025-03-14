#ifndef __MML_AST_CALL_NODE_H__
#define __MML_AST_CALL_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>

namespace mml {

  /**
   * Class for describing function call nodes.
   */
  class function_call_node: public cdk::expression_node {
    cdk::expression_node *_expr;
    cdk::sequence_node *_arguments;
  


  public:
    inline function_call_node(int lineno, cdk::expression_node *expr, cdk::sequence_node *arguments) :
        expression_node(lineno), _expr(expr), _arguments(arguments) {
    }

  public:

    inline cdk::sequence_node *arguments() {
      return _arguments;
    }

    inline cdk::expression_node *expr() {
      return _expr;
    }

    inline cdk::expression_node *argument(size_t ix) {
      return dynamic_cast<cdk::expression_node*>(_arguments->node(ix));
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // mml

#endif
