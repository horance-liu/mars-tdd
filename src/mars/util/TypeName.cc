#include <mars/util/TypeName.h>

#if defined(__GNUC__)

#include <cxxabi.h>

namespace {
  struct Demangler {
    Demangler(const std::type_info& type) :
      mangled(demangle(type)) {}

    ~Demangler() {
      ::free(mangled);
    }

    std::string name() const {
      return mangled;
    }

  private:
    static char* demangle(const std::type_info& type) {
      auto status = 0;
      return abi::__cxa_demangle(type.name(), 0, 0, &status);
    }

  private:
    char* mangled;
  };
}

#endif

#include <stdlib.h>

std::string getDemangledName(const std::type_info& type) {
#if defined(__GNUC__)
  return type.name();
  //return Demangler(type).name();
#else
  return type.name();
#endif
}
