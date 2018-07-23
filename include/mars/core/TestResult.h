#ifndef HB35561AB_6A52_4C50_9F89_EF4FE215067E
#define HB35561AB_6A52_4C50_9F89_EF4FE215067E

struct TestResult {
  TestResult();

  void startTestCase();
  int runCount() const;

private:
  int numOfRuns;
};

#endif
