#ifndef HA05FD85E_53A7_4E57_B166_26C86647DEC5
#define HA05FD85E_53A7_4E57_B166_26C86647DEC5

#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/def/FixtureDef.h>
#include <mars/def/TestDef.h>
#include <stack>

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

#endif
