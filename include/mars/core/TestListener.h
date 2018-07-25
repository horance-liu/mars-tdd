#ifndef H76B7D843_866D_47F0_A922_96F5E8E348E8
#define H76B7D843_866D_47F0_A922_96F5E8E348E8

struct Test;
struct TestFailure;

struct TestListener {
  virtual void startTestRun(const Test&) {}
  virtual void endTestRun(const Test&) {}

  virtual void startTestCase(const Test&) {}
  virtual void endTestCase(const Test&) {}

  virtual void addFailure(const TestFailure&) {}

  virtual ~TestListener() {}
};

#endif
