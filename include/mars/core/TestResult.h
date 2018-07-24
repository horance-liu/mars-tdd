#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

#include <string>
#include <vector>

struct TestCaseFunctor;

struct TestResult {
  TestResult();

  void startTestCase();
  int runCount() const;

  int failCount() const;
  int errorCount() const;

  bool protect(const TestCaseFunctor&);

  const std::vector<std::string> getFailures() const;

private:
  void addFailure(std::string&& msg);
  void addError();

private:
  int numOfRuns;
  int numOfFails;
  int numOfErrors;

  std::vector<std::string> failures;
};

#endif
