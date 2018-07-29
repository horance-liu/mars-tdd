#include <mars/listener/collector/TimeCollector.h>
#include <mars/core/TestResult.h>
#include <mars/core/TestCase.h>
#include <mars/core/TestSuite.h>
#include <gtest/gtest.h>

namespace {
  struct TimeCollectorSpec : testing::Test {
  protected:
    TimeCollectorSpec() {
      result.addListener(clock);
    }

    void run(::Test& test) {
      result.runRootTest(test);
    }

    void assertTime(const TimeVal& val) {
      ;
    }

  protected:
    TestResult result;
    TimeCollector clock;
  };
}

TEST_F(TimeCollectorSpec, should_be_successful) {
  TestSuite suite;
  suite.add(new TestCase);

  run(suite);
  ASSERT_TRUE(clock.totalTime().tv_usec > 0);
}
