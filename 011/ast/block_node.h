#ifndef __MML_AST_BLOCK_NODE_H__
#define __MML_AST_BLOCK_NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing block nodes.
   */
  class block_node: public cdk::basic_node {
    cdk::sequence_node *_decls, *_instrs;

  public:
    inline block_node(int lineno, cdk::sequence_node *decls, cdk::sequence_node *instrs) :
        cdk::basic_node(lineno), _decls(decls), _instrs(instrs) {
    }

  public:
    inline cdk::sequence_node *decls() {
      return _decls;
    }

    inline cdk::sequence_node *instrs() {
      return _instrs;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // mml

#endif
