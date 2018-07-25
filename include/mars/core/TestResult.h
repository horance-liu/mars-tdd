#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

#include <string>
#include <vector>
#include <mars/except/TestFailure.h>

struct Test;
struct TestListener;
struct TestCaseFunctor;

struct TestResult {
  void addListener(TestListener& listener);

  void runRootTest(Test&);

  void startTestCase(const Test&);
  void endTestCase(const Test&);

  bool protect(const TestCaseFunctor&);

private:
  void addFailure(std::string&&, bool);

private:
  std::vector<TestFailure> failures;
  std::vector<TestListener*> listeners;
};

#endif
