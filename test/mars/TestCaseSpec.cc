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

    void tearDown() {
      result += "[tearDown]";
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

TEST_F(TestCaseSpec, full_life_cycle_for_test_case) {
  test.run();
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}
