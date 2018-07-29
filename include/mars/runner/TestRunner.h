#ifndef H4B609426_F051_4F3B_B960_1F814F38029B
#define H4B609426_F051_4F3B_B960_1F814F38029B

#include <mars/core/TestResult.h>
#include <mars/listener/text/ColorfulPrinter.h>
#include <iostream>

struct TestRunner {
  TestRunner(std::ostream& = std::cout);
  ~TestRunner();

  void run();

private:
  TestResult result;
  ColorfulPrinter printer;
  Test* root;
};

#endif
