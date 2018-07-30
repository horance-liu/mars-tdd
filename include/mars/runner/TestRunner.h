#ifndef H4B609426_F051_4F3B_B960_1F814F38029B
#define H4B609426_F051_4F3B_B960_1F814F38029B

#include <mars/core/TestResult.h>

struct TestFactory;

struct TestRunner {
  TestRunner(TestListener&, TestFactory&);
  ~TestRunner();

  void run();

private:
  TestResult result;
  Test* root;
};

#endif
