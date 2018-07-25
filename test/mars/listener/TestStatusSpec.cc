#include <mars/listener/TestStatus.h>
#include <mars/core/TestResult.h>
#include <mars/core/TestCase.h>
#include <mars/except/AssertionError.h>
#include <gtest/gtest.h>

namespace {
  struct TestStatusSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

  private:
    void SetUp() override {
      result.addListener(status);
    }

  protected:
    TestResult result;
    TestStatus status;
  };
}

TEST_F(TestStatusSpec, should_be_successful) {
  TestCase test;
  run(test);
  ASSERT_TRUE(status.successful());
}

namespace {
  struct FailureOnRunningTest : TestCase {
  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestStatusSpec, should_be_failed) {
  FailureOnRunningTest test;
  run(test);
  ASSERT_FALSE(status.successful());
}
