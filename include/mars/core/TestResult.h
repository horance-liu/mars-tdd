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

  int errorCount() const;

  bool protect(const TestCaseFunctor&);

  const std::vector<TestFailure>& getFailures() const;

private:
  void addFailure(std::string&& msg);
  void addError(std::string&& msg);

private:
  std::vector<TestFailure> failures;
  std::vector<TestListener*> listeners;
};

#endif
