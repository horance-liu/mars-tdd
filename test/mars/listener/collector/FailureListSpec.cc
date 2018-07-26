#include <mars/listener/collector/FailureList.h>
#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
#include <gtest/gtest.h>

struct FailureListerSpec : testing::Test {
protected:
  void run(::Test& test) {
    test.run(result);
  }

private:
  void SetUp() override {
    result.addListener(list);
  }

protected:
  FailureList list;
  TestResult result;
};

namespace {
  struct FailureOnRunningTest : TestCase {
    const char* expectMsg() const {
      return "assertion fail in the runTest\n"
              "product.cc:57\n"
              "expected value == 2, but got 3";
    }

  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(FailureListerSpec, extract_except_msg_on_running_test_failed) {
  FailureOnRunningTest test;
  run(test);

  list.foreach([&test](auto& fail) {
    ASSERT_TRUE(fail.isFailure());
    ASSERT_EQ(test.expectMsg(), fail.getExceptionMsg());
  });
}
