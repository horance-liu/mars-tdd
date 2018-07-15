#include <mars/core/TestCase.h>
#include <gtest/gtest.h>

namespace {
  std::string result;

  struct WasRun : TestCase {
  private:
    void setUp() override {
      result += "[setUp]";
    }

    void runTest() override {
      result += "[runTest]";
    }

    void tearDown() override {
      result += "[tearDown]";
    }
  };
}

TEST(TestCaseSpec, full_life_cycle_for_test_case) {
  WasRun test;
  test.run();
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}
