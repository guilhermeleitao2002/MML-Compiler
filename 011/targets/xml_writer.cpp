#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated

#include "mml_parser.tab.h"
//----------------------------------------------------------------------------
static std::string qualifier_name(int qualifier) {
  if (qualifier == tPUBLIC) return "public";
  if (qualifier == tFOREIGN)return "foreign";
  if (qualifier == tFORWARD)return "forward";
  else
    return "unknown qualifier";
}
//---------------------------------------------------------------------------

void mml::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void mml::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}
void mml::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  process_literal(node, lvl);
}
void mml::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_unary_operation(node, lvl);
}
void mml::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void mml::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_unary_operation(cdk::unary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void mml::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_unary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_binary_operation(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void mml::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}
void mml::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void mml::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void mml::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

// void mml::xml_writer::do_program_node(mml::program_node * const node, int lvl) {
//   openTag(node, lvl);
//   node->statements()->accept(this, lvl + 4);
//   closeTag(node, lvl);
// }

//---------------------------------------------------------------------------

void mml::xml_writer::do_evaluation_node(mml::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void mml::xml_writer::do_print_node(mml::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_while_node(mml::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_sizeof_node(mml::sizeof_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->expression()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_null_node(mml::null_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_input_node(mml::input_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_return_node(mml::return_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node->retval()) node->retval()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void mml::xml_writer::do_variable_declaration_node(mml::variable_declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  reset_new_symbol();

  os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
      << qualifier_name(node->qualifier()) << "' type='" << cdk::to_string(node->type()) << "'>" << std::endl;

  if (node->initializer()) {
    openTag("initializer", lvl);
    node->initializer()->accept(this, lvl + 4);
    closeTag("initializer", lvl);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void mml::xml_writer::do_stop_node(mml::stop_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->level() << "</" << node->label() << ">" << std::endl;
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_next_node(mml::next_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->level() << "</" << node->label() << ">" << std::endl;
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_block_node(mml::block_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("declarations", lvl);
  if (node->decls()) {
    node->decls()->accept(this, lvl + 4);
  }
  closeTag("declarations", lvl);
  openTag("instructions", lvl);
  if (node->instrs()) {
    node->instrs()->accept(this, lvl + 4);
  }
  closeTag("instructions", lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_function_call_node(mml::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->expr()->accept(this, lvl + 2);
  openTag("arguments", lvl);
  if (node->arguments()) node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_function_definition_node(mml::function_definition_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // remember symbol so that args and body know
  _function = new_symbol();
  reset_new_symbol();

  _inFunctionBody = true;
  _symtab.push(); // scope of args

  openTag("arguments", lvl);
  if (node->variables()) {
    node->variables()->accept(this, lvl + 4);
  }
  closeTag("arguments", lvl);
  node->block()->accept(this, lvl + 2);
  closeTag(node, lvl);

  _symtab.pop(); // scope of args
  _inFunctionBody = false;
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_address_of_node(mml::address_of_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_stack_alloc_node(mml::stack_alloc_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_index_node(mml::index_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("base", lvl);
  node->base()->accept(this, lvl + 2);
  closeTag("base", lvl);
  openTag("index", lvl);
  node->index()->accept(this, lvl + 2);
  closeTag("index", lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_identity_node(mml::identity_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void mml::xml_writer::do_if_node(mml::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void mml::xml_writer::do_if_else_node(mml::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}
