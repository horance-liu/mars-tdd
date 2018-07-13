#include <gtest/gtest.h>
#include <mars/core/TestMethod.h>

namespace {
  bool wasRun = false;

  struct WasRun {
    void testMethod() {
      wasRun = true;
    }
  };
}

TEST(TestCaseSpec, make_sure_test_method_was_ran) {
  WasRun test;
  ASSERT_FALSE(wasRun);

  TestMethod<WasRun> method(&WasRun::testMethod);
  method.run();
  ASSERT_TRUE(wasRun);
}
