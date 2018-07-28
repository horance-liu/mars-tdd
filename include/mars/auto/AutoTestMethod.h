#ifndef H0113CA37_8863_4530_B836_ADB0121A5332
#define H0113CA37_8863_4530_B836_ADB0121A5332

#include <mars/auto/TestMethodRegistry.h>
#include <mars/core/TestMethod.h>

struct AutoTestMethod {
  template <typename Fixture>
  AutoTestMethod(int id, const char* name, void(Fixture::*method)()) {
    auto& registry = TestMethodRegistry<Fixture>::instance();
    registry.put(id, new TestMethod<Fixture>(method, name));
  }
};

#endif
