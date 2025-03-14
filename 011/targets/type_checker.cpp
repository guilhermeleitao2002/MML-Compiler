#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

// must come after other #includes
#include "mml_parser.tab.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void mml::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

//protected:
void mml::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}

void mml::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

void mml::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}

void mml::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}

void mml::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

void mml::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------

void mml::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  ASSERT_UNSPEC;
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT) && !node->left()->is_typed(cdk::TYPE_DOUBLE)) throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT) && !node->right()->is_typed(cdk::TYPE_DOUBLE)) throw std::string("wrong type in right argument of binary expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void mml::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  auto symbol = _symtab.find(id);

  if (symbol) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void mml::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void mml::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  node->lvalue()->accept(this, lvl);
  node->rvalue()->accept(this, lvl+2);  

  node->type(node->lvalue()->type());

  if (node->lvalue()->is_typed(node->rvalue()->type()->name())) {} // is valid
  else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE) && node->rvalue()->is_typed(cdk::TYPE_INT)) {} // is valid
  else throw std::string("wrong type in right of assignment expression");
}

//---------------------------------------------------------------------------

void mml::type_checker::do_evaluation_node(mml::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl+2);
}

void mml::type_checker::do_print_node(mml::print_node *const node, int lvl) {
  node->argument()->accept(this, lvl+2);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_while_node(mml::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl+4);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_sizeof_node(mml::sizeof_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->expression()->accept(this, lvl+2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_null_node(mml::null_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_input_node(mml::input_node * const node, int lvl) {
  node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_return_node(mml::return_node * const node, int lvl) {
  _function = _parent->new_symbol();
  if(!_function) _function = _symtab.find("_main");
  std::cout << "RETURN NODE " << _function->name() << std::endl;
  if (node->retval()) {
    if (_function->type() != nullptr && _function->is_typed(cdk::TYPE_VOID)) throw std::string(
        "initializer specified for void function.");

    node->retval()->accept(this, lvl+2);

    if (_function->is_typed(cdk::TYPE_INT)) {
      if (!node->retval()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (_function->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->retval()->is_typed(cdk::TYPE_INT) && !node->retval()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (_function->is_typed(cdk::TYPE_STRING)) {
      if (!node->retval()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (_function->is_typed(cdk::TYPE_POINTER)) {
      //DAVID: FIXME: trouble!!!
      int ft = 0, rt = 0;
      auto ftype = _function->type();
      while (ftype->name() == cdk::TYPE_POINTER) {
        ft++;
        ftype = cdk::reference_type::cast(ftype)->referenced();
      }
      auto rtype = node->retval()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }

      bool compatible = (ft == rt) && (rtype == nullptr || (rtype != nullptr && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else if (_function->is_typed(cdk::TYPE_FUNCTIONAL)) {
      std::cout << "RETURNS: " << node->retval()->type()->to_string() << std::endl;
      if (!node->retval()->is_typed(cdk::functional_type::cast(_function->type())->output(0)->name())) {
        throw std::string("wrong type for initializer (return type doesnt match).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  } else {
    if (_function->type() != nullptr && !_function->is_typed(cdk::TYPE_VOID)) throw std::string(
        "missing return value for non-void function.");
  }
}

//---------------------------------------------------------------------------

static bool check_function_types(std::shared_ptr<cdk::functional_type> left, std::shared_ptr<cdk::functional_type> right) {
  if (left->output(0)->name() == cdk::TYPE_FUNCTIONAL) {
     if (!(right->output(0)->name() == cdk::TYPE_FUNCTIONAL && 
          check_function_types(cdk::functional_type::cast(left->output(0)), cdk::functional_type::cast(right->output(0))))) {
      return false;
    }

  } else if (left->output(0)->name() == cdk::TYPE_DOUBLE) {
    if (!((right->output(0)->name() == cdk::TYPE_INT) || (right->output(0)->name() == cdk::TYPE_DOUBLE))) {
      return false;
    }
  } else if ((left->output(0)->name() != right->output(0)->name())) {
    return false;
  }

  if (left->input_length() != right->input_length()) {
    return false;
  }
  for (size_t tx = 0; tx < left->input_length(); tx++) {
    if (left->input(tx)->name() == cdk::TYPE_FUNCTIONAL) {
      if (!(right->input(tx)->name() == cdk::TYPE_FUNCTIONAL && 
          check_function_types(cdk::functional_type::cast(left->input(tx)), cdk::functional_type::cast(right->input(tx))))) {
        return false;
      }
    } else if (right->input(tx)->name() == cdk::TYPE_DOUBLE) {
      if ((!((left->input(tx)->name() == cdk::TYPE_INT) || (left->input(tx)->name() == cdk::TYPE_DOUBLE)))) {
        return false;
      }
    } else if ((left->input(tx)->name() != right->input(tx)->name())) {
      return false;
    }
  }

  return true;
}


void mml::type_checker::do_variable_declaration_node(mml::variable_declaration_node * const node, int lvl) {
  const std::string &id = node->identifier();

  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl+2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      //DAVID: FIXME: trouble!!!
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else if (node->is_typed(cdk::TYPE_FUNCTIONAL)) {
      if (!node->initializer()->is_typed(cdk::TYPE_FUNCTIONAL) ||
          ! check_function_types(cdk::functional_type::cast(node->type()), cdk::functional_type::cast(node->initializer()->type()))) {
        throw std::string("wrong type for initializer (function expected).");
      }
    } else if(node->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(node->initializer()->type());      
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  if(node->is_typed(cdk::TYPE_FUNCTIONAL)) {
    auto symbol = mml::make_symbol(node->type(), id, 0, true, node->qualifier());
    std::shared_ptr<cdk::functional_type> ftype = cdk::functional_type::cast(node->type());
    symbol->set_argument_types(ftype->input()->components());
    if (_symtab.insert(id, symbol)) {
      _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
    } else {
      throw std::string("function '" + id + "' redeclared");
    }
  } else {
    auto symbol = mml::make_symbol(node->type(), id, 0, false, node->qualifier()); // we assume its a variable
    if (_symtab.insert(id, symbol)) {
      _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
    } else {
      throw std::string("variable '" + id + "' redeclared");
    }
  }

  if (node->qualifier() == tFOREIGN) {
    _parent->new_symbol()->set_foreign(true);
  }
}

//---------------------------------------------------------------------------

void mml::type_checker::do_stop_node(mml::stop_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void mml::type_checker::do_next_node(mml::next_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void mml::type_checker::do_block_node(mml::block_node * const node, int lvl) {
  if(node->decls()) node->decls()->accept(this, lvl+2);
  if(node->instrs()) node->instrs()->accept(this, lvl+2);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_function_call_node(mml::function_call_node * const node, int lvl) {
  ASSERT_UNSPEC;

  std::shared_ptr<mml::symbol> symbol;
  std::string id;
  if (node->expr() != nullptr) {
    id = (dynamic_cast<cdk::variable_node *>(dynamic_cast<cdk::rvalue_node *>(node->expr())->lvalue()))->name();
    symbol = _symtab.find(id);

    if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
    if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");

  } else { // call is recursive
    if(_function->isMain()) throw std::string("cannot call main function recursively.");
    id = _function->name();
    symbol = _function;
  }

  node->type(cdk::functional_type::cast(symbol->type())->output(0));

  if(node->arguments() != nullptr) {
    if (node->arguments()->size() == symbol->number_of_arguments()) {
      node->arguments()->accept(this, lvl+4);
      for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
        if (node->argument(ax)->type() == symbol->argument_type(ax)) continue;
        if (symbol->argument_is_typed(ax, cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
        throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
      }
    } else {
      throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match definition ("
            + std::to_string(symbol->number_of_arguments()) + ").");
    }
  }
}

//---------------------------------------------------------------------------

void mml::type_checker::do_function_definition_node(mml::function_definition_node * const node, int lvl) {
  if(node->variables()) node->variables()->accept(this, lvl+2); // may be different for main function

  if(!node->isMain() && !node->is_typed(cdk::TYPE_FUNCTIONAL)) {
    // remember symbol so that args know
    
    std::vector<std::shared_ptr<cdk::basic_type>> argtypes;
    std::vector<std::shared_ptr<cdk::basic_type>> outtype;
    outtype.push_back(node->type());
    if(node->variables()) {
      for (size_t ax = 0; ax < node->variables()->size(); ax++) {
        argtypes.push_back(node->argument(ax)->type());
        if(!_parent->new_symbol()->is_typed(cdk::TYPE_UNSPEC)) {
          if (node->argument(ax)->type() == _parent->new_symbol()->argument_type(ax)) continue;
          if (_parent->new_symbol()->argument_is_typed(ax, cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
        }
        throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of function." );
      }
    }
    
    node->type(cdk::functional_type::create(argtypes, outtype));
    std::cout << "FUNCTION DEFINITION: " << node->type()->to_string() << std::endl;
    _function = mml::make_symbol(node->type(), "_", 0, true, 0);
    _parent->set_new_symbol(_function);
  } else {
    auto symbol = mml::make_symbol(cdk::primitive_type::create(4, cdk::TYPE_INT), "_main", 0, true, tPUBLIC);
    _symtab.insert("_main", symbol);
    _function = symbol;
  }
  
  node->block()->accept(this, lvl+2);
  _function = nullptr;
}

//---------------------------------------------------------------------------

void mml::type_checker::do_address_of_node(mml::address_of_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl+2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

//---------------------------------------------------------------------------

void mml::type_checker::do_stack_alloc_node(mml::stack_alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl+2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  //DAVID TODO FIXME
  auto mytype = cdk::reference_type::create(4, cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  node->type(mytype);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_index_node(mml::index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;

  if (node->base()) {
    node->base()->accept(this, lvl+2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl+2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

//---------------------------------------------------------------------------

void mml::type_checker::do_identity_node(mml::identity_node * const node, int lvl) {
  ASSERT_UNSPEC;
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_if_node(mml::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl+4);
  node->block()->accept(this, lvl+4);
}

void mml::type_checker::do_if_else_node(mml::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl+4);
  node->thenblock()->accept(this, lvl+4);
  node->elseblock()->accept(this, lvl+4);
}
