#ifndef HA23D408A_9BBE_445C_A0EB_3CE8F1263BF9
#define HA23D408A_9BBE_445C_A0EB_3CE8F1263BF9

#include <mars/factory/TestFixtureFactory.h>
#include <mars/factory/TestSuiteFactory.h>

template<typename Fixture>
struct AutoTestFixture {
  AutoTestFixture(const char* name) {
    auto& root = TestSuiteFactory::root();
    auto& leaf = TestFixtureFactory<Fixture>::instance(name);
    root.add(leaf);
  }
};

#endif
