#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

#include <string>
#include <vector>
#include <mars/except/TestFailure.h>

struct TestCaseFunctor;

struct TestResult {
  TestResult();

  void startTestCase();
  int runCount() const;

  int failCount() const;
  int errorCount() const;

  bool protect(const TestCaseFunctor&);

  using TestFailures = std::vector<TestFailure>;
  const TestFailures& getFailures() const;

  using TestErrors = std::vector<std::string>;
  const TestErrors& getErrors() const;

private:
  void addFailure(std::string&& msg);
  void addError(std::string&& msg);

private:
  int numOfRuns;
  TestFailures failures;
  TestErrors errors;
};

#endif
