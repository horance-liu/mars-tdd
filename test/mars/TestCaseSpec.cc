#include <gtest/gtest.h>
#include <mars/core/TestFixture.h>
#include <mars/core/TestMethod.h>

namespace {
  std::string result;

  struct WasRun : TestFixture {
    void setUp() override {
      result += "[setUp]";
    }

    void testMethod() {
      result += "[runTest]";
    }

    void tearDown() override {
      result += "[tearDown]";
    }
  };

  struct TestCaseSpec : testing::Test {
  private:
    void SetUp() override {
      result.clear();
    }
  };
}

TEST_F(TestCaseSpec, full_life_cycle_for_test_case) {
  TestMethod<WasRun> test(&WasRun::testMethod);
  test.run();
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}
