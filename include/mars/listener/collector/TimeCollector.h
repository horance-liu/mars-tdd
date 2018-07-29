#ifndef HB356FE78_21BF_4050_8C11_FBA5ECF90CA4
#define HB356FE78_21BF_4050_8C11_FBA5ECF90CA4

#include <mars/core/TestListener.h>
#include <mars/util/TimeVal.h>
#include <stack>

struct TimeCollector : TestListener {
  ~TimeCollector();

  TimeVal caseTime() const;
  TimeVal suiteTime() const;
  TimeVal totalTime() const;

  void startTestRun(const Test&) override;
  void endTestRun(const Test&) override;

  void startTestSuite(const Test&) override;
  void endTestSuite(const Test&) override;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

private:
  void start();
  void end(TimeVal&);
  void pop();

private:
  TimeVal casetime;
  TimeVal suitetime;
  TimeVal totaltime;

  struct Timer;
  std::stack<Timer*> stack;
};

#endif
