#ifndef H073487E3_C156_41DA_B6CB_F37628E503B3
#define H073487E3_C156_41DA_B6CB_F37628E503B3


#ifndef HC1529C5B_742D_4014_BBBF_7533B3E13905
#define HC1529C5B_742D_4014_BBBF_7533B3E13905

#include <iostream>

#include <mars/listener/collector/FailureList.h>
#include <mars/listener/collector/TestCollector.h>
#include <mars/listener/collector/TestStatus.h>
#include <mars/listener/collector/TimeCollector.h>

struct TestInfo;

struct ColorfulPrinter : TestListener {
  explicit ColorfulPrinter(std::ostream& = std::cout);
  ~ColorfulPrinter();

private:
  void startTestRun(const Test&) override;
  void endTestRun(const Test&) override;

  void startTestSuite(const Test&) override;
  void endTestSuite(const Test&) override;

  void startTestCase(const Test&) override;
  void endTestCase(const Test&) override;

  void addFailure(const TestFailure&) override;

private:
  bool lastFailed;
  std::ostream& out;

  struct Writer;
  Writer* writer;

  TestStatus status;
  TestCollector collector;
  FailureList lister;
  TimeCollector clock;
};

#endif

#endif
