#ifndef H057C6A15_5A98_4164_B057_160C0E24DC14
#define H057C6A15_5A98_4164_B057_160C0E24DC14

#include <mars/core/TestListener.h>

struct TestCollector : TestListener {
  TestCollector();

  int runCount() const;

private:
  void startTestCase(const Test&) override;

private:
  int numOfRuns;
};

#endif
