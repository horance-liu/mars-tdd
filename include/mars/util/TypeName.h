#ifndef H4D9C485F_0ABA_4358_8C46_66625537AF20
#define H4D9C485F_0ABA_4358_8C46_66625537AF20

#include <string>
#include <typeinfo>

std::string getDemangledName(
    const std::type_info& typeInfo);

template<typename T>
struct TypeName {
  static std::string value() {
    return getDemangledName(typeid(T));
  }
};

template<>
struct TypeName<std::string> {
  static std::string value() {
    return "std::string";
  }
};

template<>
struct TypeName<std::wstring> {
  static std::string value() {
    return "std::wstring";
  }
};

template<>
struct TypeName<std::nullptr_t> {
  static std::string value() {
    return "std::nullptr_t";
  }
};

#endif
