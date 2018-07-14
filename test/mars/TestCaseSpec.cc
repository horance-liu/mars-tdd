#include <gtest/gtest.h>
#include <mars/core/TestMethod.h>

namespace {
  bool wasRun = false;
  bool wasSetUp = false;
  std::string result;

  struct WasRun {
    void setUp() {
      wasSetUp = true;
      result += "[setUp]";
    }

    void testMethod() {
      wasRun = true;
      result += "[runTest]";
    }
  };

  struct TestCaseSpec : testing::Test {
  private:
    void SetUp() override {
      wasRun = false;
      wasSetUp = false;
      result.clear();
    }

  protected:
    TestMethod<WasRun> test = &WasRun::testMethod;
  };
}

TEST_F(TestCaseSpec, make_sure_test_method_was_ran) {
  ASSERT_FALSE(wasRun);
  test.run();
  ASSERT_TRUE(wasRun);
}

TEST_F(TestCaseSpec, should_setup_before_run_test) {
  ASSERT_FALSE(wasSetUp);
  test.run();
  ASSERT_TRUE(wasSetUp);
}

TEST_F(TestCaseSpec, make_sure_setup_before_run_test) {
  test.run();
  ASSERT_EQ("[setUp][runTest]", result);
}
