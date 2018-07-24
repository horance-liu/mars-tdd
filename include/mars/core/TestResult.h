#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

struct TestCaseFunctor;

struct TestResult {
  TestResult();

  void startTestCase();
  int runCount() const;

  int failCount() const;
  int errorCount() const;

  bool protect(const TestCaseFunctor&);

private:
  void addFailure();
  void addError();

private:
  int numOfRuns;
  int numOfFails;
  int numOfErrors;
};

#endif
