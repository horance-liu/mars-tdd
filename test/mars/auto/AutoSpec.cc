#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/def/FixtureDef.h>
#include <mars/def/TestDef.h>
#include <mars/runner/TestRunner.h>
#include <mars/listener/text/TextProgress.h>
#include <stack>
#include <queue>
#include <sstream>

namespace {
  FIXTURE(StackSpec) {
    std::stack<int> v;

    SETUP {
      v.push(1);
      v.push(2);
    }

    TEST("apply stack with pop 0 time") {
      ASSERT_EQ(2, v.top());
    }

    TEST("apply stack with pop 1 time") {
      v.pop();
      ASSERT_EQ(1, v.top());
    }

    TEST("apply stack with pop 2 times") {
      v.pop();
      v.pop();
      ASSERT_TRUE(v.empty());
    }
  };

  FIXTURE(QueueSpec) {
    std::queue<int> q;

    SETUP {
      q.push(1);
      q.push(2);
    }

    TEST("apply pop 0 time") {
      ASSERT_EQ(1, q.front());
      ASSERT_EQ(2, q.back());
    }

    TEST("apply pop 1 time") {
      q.pop();
      ASSERT_EQ(2, q.front());
      ASSERT_EQ(2, q.back());
    }

    TEST("apply pop 2 times"){
      q.pop();
      q.pop();
      ASSERT_TRUE(q.empty());
    }
  };

  template <typename Fixture>
  struct GenericAutoSpec : testing::Test {
  protected:
    GenericAutoSpec()
      : progress(ss)
      , runner(progress, factory()) {}

  private:
    static TestFactory& factory() {
      return TestFixtureFactory<Fixture>::instance();
    }

  protected:
    std::ostringstream ss;
    TextProgress progress;
    TestRunner runner;
  };

  using AutoStackSpec = GenericAutoSpec<StackSpec>;
  using AutoQueueSpec = GenericAutoSpec<QueueSpec>;
}

TEST_F(AutoStackSpec, run_stack_spec) {
  runner.run();
  ASSERT_EQ("starting...\n***\nend.\n", ss.str());
}

TEST_F(AutoQueueSpec, run_queue_spec) {
  runner.run();
  ASSERT_EQ("starting...\n***\nend.\n", ss.str());
}
