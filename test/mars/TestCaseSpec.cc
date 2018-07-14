#include <gtest/gtest.h>
#include <mars/core/TestMethod.h>

namespace {
  bool wasRun = false;
  bool wasSetUp = false;

  struct WasRun {
    void setUp() {
      wasSetUp = true;
    }

    void testMethod() {
      wasRun = true;
    }
  };

  struct TestCaseSpec : testing::Test {
  private:
    void SetUp() override {
      wasRun = false;
      wasSetUp = false;
    }
  };
}

TEST_F(TestCaseSpec, make_sure_test_method_was_ran) {
  TestMethod<WasRun> test(&WasRun::testMethod);

  ASSERT_FALSE(wasRun);
  test.run();
  ASSERT_TRUE(wasRun);
}

TEST_F(TestCaseSpec, should_setup_before_run_test) {
  TestMethod<WasRun> test(&WasRun::testMethod);

  ASSERT_FALSE(wasSetUp);
  test.run();
  ASSERT_TRUE(wasSetUp);
}
