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

  void startTestCase(const Test&);
  void endTestCase(const Test&);

  bool protect(const TestCaseFunctor&);

  const std::vector<TestFailure>& getFailures() const;

private:
  void onFail(std::string&& msg);
  void onError(std::string&& msg);
  void addFailure(TestFailure&&);

private:
  std::vector<TestFailure> failures;
  std::vector<TestListener*> listeners;
};

#endif
