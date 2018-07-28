#ifndef HA23D408A_9BBE_445C_A0EB_3CE8F1263BF9
#define HA23D408A_9BBE_445C_A0EB_3CE8F1263BF9

#include <mars/auto/AutoTestFactory.h>
#include <mars/auto/TestFactorySuite.h>

template<typename Fixture>
struct AutoTestSuite {
  AutoTestSuite() {
    TestFactorySuite::instance().addFactory(atom);
  }

private:
  AutoTestFactory<Fixture> atom;
};

#endif
