#ifndef __MML_TARGETS_SYMBOL_H__
#define __MML_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace mml {

  class symbol {
    std::shared_ptr<cdk::basic_type> _type;
    std::string _name;
    long _value; // hack!
    bool _function; // false for variables
    int _offset = 0; // 0 (zero) means global variable/function
    bool _isMain;
    int _qualifier;
    bool _is_Foreign;
    std::vector<std::shared_ptr<cdk::basic_type>> _argument_types;

  public:
    symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value, bool function, int qualifier) :
        _type(type), _name(name), _value(value), _function(function), _isMain(false), _qualifier(qualifier){
    }

    virtual ~symbol() {
      // EMPTY
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    const std::string &name() const {
      return _name;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    void set_foreign(bool val) {
      _is_Foreign = val;
    }
    int qualifier() const {
      return _qualifier;
    }
    bool is_foreign() const {
      return _is_Foreign;
    }
   
   void set_type(std::shared_ptr<cdk::basic_type> t) {
      _type = t;
    }
    int offset() const {
      return _offset;
    }
    void set_offset(int offset) {
      _offset = offset;
    }
    bool isFunction() const {
      return _function;
    }
    void setFunction(bool val) {
      _function = val;
    }
    bool global() const {
      return _offset == 0;
    }
    bool isMain() const {
      return _isMain;
    }
    void setMain(bool val) {
      _isMain = val;
    }
    bool argument_is_typed(size_t ax, cdk::typename_type name) const {
      return _argument_types[ax]->name() == name;
    }
    std::shared_ptr<cdk::basic_type> argument_type(size_t ax) const {
      return _argument_types[ax];
    }

    size_t argument_size(size_t ax) const {
      return _argument_types[ax]->size();
    }

    size_t number_of_arguments() const {
      return _argument_types.size();
    }

    void set_argument_types(const std::vector<std::shared_ptr<cdk::basic_type>> &types) {
      _argument_types = types;
    }
  };
  inline auto make_symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value, bool function, int qualifier) {
    return std::make_shared<symbol>(type, name, value, function, qualifier);
  }


} // mml

#endif
