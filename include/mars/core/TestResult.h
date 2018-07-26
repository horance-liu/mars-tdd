#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

#include <string>
#include <vector>
#include <mars/except/TestFailure.h>
#include <mars/core/internal/TestCaseProtector.h>

struct Test;
struct TestListener;
struct TestCaseFunctor;
struct BareTestCase;

struct TestResult : private TestCaseProtector {
  void addListener(TestListener& listener);

  void startTestRun(const Test&);
  void endTestRun(const Test&);

  void startTestSuite(const Test&);
  void endTestSuite(const Test&);

  void runTestCase(BareTestCase&);

private:
  bool operator()(const TestCaseFunctor&) override;

private:
  void addFailure(std::string&&, bool);

private:
  std::vector<TestFailure> failures;
  std::vector<TestListener*> listeners;
};

#endif
