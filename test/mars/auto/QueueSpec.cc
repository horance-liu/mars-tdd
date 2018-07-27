#include <mars/core/TestFixture.h>
#include <mars/core/TestMethod.h>
#include <mars/core/TestSuite.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <gtest/gtest.h>
#include <stack>

namespace {
  struct StackSpec : TestFixture {
    std::stack<int> v;

    void setUp() override {
      v.push(1);
      v.push(2);
    }

    void apply_pop_0_time() {
      ASSERT_EQ(2, v.top());
    }

    void apply_pop_1_time() {
      v.pop();
      ASSERT_EQ(1, v.top());
    }

    void apply_pop_2_times() {
      v.pop();
      v.pop();
      ASSERT_TRUE(v.empty());
    }
  };

  struct ManualRegisterSpecX : testing::Test {
  protected:
    ManualRegisterSpecX() : progress(ss) {
      result.addListener(progress);
    }

    void run(::Test& test) {
      result.runRootTest(test);
    }

    void assertOutput(const char* output) {
      ASSERT_EQ(ss.str(), output);
    }

  protected:
    std::ostringstream ss;
    TestResult result;
    TextProgress progress;
  };
}


TEST_F(ManualRegisterSpecX, manually_registering_test_cases) {
  TestSuite suite("StackSpec");
  suite.add(new TestMethod<StackSpec>(&StackSpec::apply_pop_0_time));
  suite.add(new TestMethod<StackSpec>(&StackSpec::apply_pop_1_time));
  suite.add(new TestMethod<StackSpec>(&StackSpec::apply_pop_2_times));

  run(suite);
  assertOutput("starting...\n***\nend.\n");
}
