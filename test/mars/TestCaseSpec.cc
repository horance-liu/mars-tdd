#include <gtest/gtest.h>
#include <mars/core/TestMethod.h>

namespace {
  std::string result;

  struct WasRun {
    void setUp() {
      result += "[setUp]";
    }

    void testMethod() {
      result += "[runTest]";
    }
  };

  struct TestCaseSpec : testing::Test {
  private:
    void SetUp() override {
      result.clear();
    }

  protected:
    TestMethod<WasRun> test = &WasRun::testMethod;
  };
}

TEST_F(TestCaseSpec, make_sure_setup_before_run_test) {
  test.run();
  ASSERT_EQ("[setUp][runTest]", result);
}
