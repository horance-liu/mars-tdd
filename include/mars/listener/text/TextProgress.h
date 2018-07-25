#ifndef HF66BB464_6C9A_4B6E_BA6B_E5A59DA55A95
#define HF66BB464_6C9A_4B6E_BA6B_E5A59DA55A95

#include <mars/core/TestListener.h>
#include <ostream>

struct TextProgress : TestListener {
  explicit TextProgress(std::ostream&);

private:
  void startTestRun(const Test&) override;
  void startTestCase(const Test&) override;
  void addFailure(const TestFailure&) override;
  void endTestRun(const Test&) override;


private:
  std::ostream& out;
};

#endif
