#ifndef HEBF15E7D_D122_42D4_B25F_D1D468AFF133
#define HEBF15E7D_D122_42D4_B25F_D1D468AFF133

#include <mars/core/Test.h>
#include <vector>

struct TestResult;

struct TestSuite : Test {
  using Test::Test;
  ~TestSuite();

  void add(Test* test);

private:
  void run(TestResult& result) override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::vector<Test*> tests;
};

#endif
