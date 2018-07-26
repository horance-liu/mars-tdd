#ifndef HEBF15E7D_D122_42D4_B25F_D1D468AFF133
#define HEBF15E7D_D122_42D4_B25F_D1D468AFF133

#include <vector>
#include <mars/core/Test.h>
#include <mars/core/internal/BareTestSuite.h>

struct TestResult;

struct TestSuite : Test, private BareTestSuite {
  using Test::Test;
  ~TestSuite();

  void add(Test* test);

private:
  void run(TestResult& result) override;
  int countTestCases() const override;

private:
  const Test& get() const override;
  void runBare(TestResult& result) override;

private:
  template <typename F>
  void foreach(F f) const;

  template <typename Init, typename F>
  Init reduce(Init init, F f) const;

private:
  std::vector<Test*> tests;
};

#endif
