#ifndef __MML_AST_FUNCTION_DEFINITION_NODE_H__
#define __MML_AST_FUNCTION_DEFINITION_NODE_H__

#include <cdk/types/basic_type.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <ast/block_node.h>
#include <cdk/ast/typed_node.h>

namespace mml {

  /**
   * Class for describing function declaration nodes.
   */
  class function_definition_node: public cdk::expression_node {
    cdk::sequence_node *_variables;
    mml::block_node *_block;
    bool _isMain;

  public:
    inline function_definition_node(int lineno, cdk::sequence_node *variables, mml::block_node *block, std::shared_ptr<cdk::basic_type> outType, bool isMain = false) :
        expression_node(lineno),  _variables(variables), _block(block), _isMain(isMain) {
      type(outType);
    }

  public:

    inline cdk::sequence_node *variables() {
      return _variables;
    }

    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_variables->node(ax));
    }

    inline mml::block_node *block() {
      return _block;
    }

    inline bool isMain() {
      return _isMain;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // mml

#endif
