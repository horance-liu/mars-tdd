#ifndef H93A07344_57E2_4859_A5F8_8394E57E38F5
#define H93A07344_57E2_4859_A5F8_8394E57E38F5

#include <mars/core/Test.h>
#include <mars/core/TestFixture.h>
#include <mars/core/internal/BareTestCase.h>

struct TestCase
  : Test
  , private TestFixture
  , private BareTestCase {

  using Test::Test;

private:
  void run(TestResult&) override;
  int countTestCases() const override;

private:
  const Test& get() const override;
  void runBare(TestCaseProtector&) override;

private:
  virtual void runTest() {}
};

#endif
