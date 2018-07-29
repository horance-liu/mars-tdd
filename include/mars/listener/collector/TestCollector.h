#ifndef H057C6A15_5A98_4164_B057_160C0E24DC14
#define H057C6A15_5A98_4164_B057_160C0E24DC14

#include <mars/core/TestListener.h>

struct TestCollector : TestListener {
  TestCollector();

  int runCount() const;
  int failCount() const;
  int errorCount() const;
  int passCount() const;
  int failTotal() const;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;
  void addFailure(const TestFailure&) override;

private:
  int numOfRuns;
  int numOfFails;
  int numOfErrors;
  int numOfPassed;
  bool lastFailed;
};

#endif
