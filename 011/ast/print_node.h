#ifndef __MML_AST_PRINT_NODE_H__
#define __MML_AST_PRINT_NODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/basic_node.h>

namespace mml {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::sequence_node *_arguments;
    bool _ln;

  public:
    inline print_node(int lineno, cdk::sequence_node *arguments, bool ln = false) :
        cdk::basic_node(lineno), _arguments(arguments), _ln(ln) {
    }

  public:
    inline cdk::sequence_node *argument() {
      return _arguments;
    }

    inline bool ln() {
      return _ln;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // mml

#endif
