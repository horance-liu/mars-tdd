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

TEST(WasRunSpec, full_life_cycle_for_test_case_using_test_case) {
  WasRun test;
  test.run();
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}

#include <mars/core/TestCase.h>
#include <gtest/gtest.h>

namespace {
  int num = 0;

  struct FooTest : TestCase {
  private:
    void runTest() override {
      num++;
    }
  };

  struct TestCaseSpec : testing::Test {
  private:
    void SetUp() override {
      num = 0;  // IMPORTANT: reset counter.
    }
  };
}

TEST_F(TestCaseSpec, run_one_simple_test) {
  FooTest foo;
  foo.run();
  ASSERT_EQ(1, num);
}
