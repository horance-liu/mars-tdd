#include <gtest/gtest.h>
#include <mars/core/TestFixture.h>
#include <mars/core/TestMethod.h>

namespace {
  bool wasSucc = false;

  struct WasSucc : TestFixture {
    void testMethod() {
      wasSucc = true;
    }
  };
}

TEST(WasSuccSpec, make_sure_test_running_is_succ) {
  TestMethod<WasSucc> test(&WasSucc::testMethod);

  ASSERT_FALSE(wasSucc);
  test.run();
  ASSERT_TRUE(wasSucc);
}
