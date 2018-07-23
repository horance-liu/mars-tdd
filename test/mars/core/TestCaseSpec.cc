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
      result.clear();
      num = 0;
    }

  protected:
    void run(::Test& test) {
      test.run();
    }
  };
}

TEST_F(TestCaseSpec, full_life_cycle_for_test_case) {
  FooTest foo;
  run(foo);
  ASSERT_EQ(1, num);
}

TEST_F(TestCaseSpec, run_one_simple_test) {
  FooTest foo;
  run(foo);
  ASSERT_EQ(1, num);
}
