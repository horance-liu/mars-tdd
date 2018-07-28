#ifndef HE38BE809_A30C_425F_8DB2_34AEECF4A5F4
#define HE38BE809_A30C_425F_8DB2_34AEECF4A5F4

#include <mars/auto/TestFactory.h>
#include <mars/auto/TestMethodRegistry.h>

template<typename Fixture>
struct AutoTestFactory : TestFactory {
private:
  Test* make() override {
    Fixture dummy; // register all test methods to registry.
    return TestMethodRegistry<Fixture>::instance().suite();
  }
};

#endif
