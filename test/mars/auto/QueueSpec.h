#ifndef H6A08EA0F_229E_44ED_998D_A59E2A10E842
#define H6A08EA0F_229E_44ED_998D_A59E2A10E842

#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/def/FixtureDef.h>
#include <mars/def/TestDef.h>
#include <queue>

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

#endif
