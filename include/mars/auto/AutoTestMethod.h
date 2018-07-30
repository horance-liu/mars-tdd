#ifndef H0113CA37_8863_4530_B836_ADB0121A5332
#define H0113CA37_8863_4530_B836_ADB0121A5332

#include <mars/factory/TestFixtureFactory.h>
#include <mars/core/TestMethod.h>

struct AutoTestMethod {
  template <typename Fixture>
  AutoTestMethod(int id, const char* name, Method<Fixture> method) {
    auto& registry = TestFixtureFactory<Fixture>::instance();
    registry.add(id, name, method);
  }
};

#endif
