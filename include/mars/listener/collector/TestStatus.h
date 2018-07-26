#ifndef H97C45242_DFDE_4DDC_89BC_66B74E37DD9E
#define H97C45242_DFDE_4DDC_89BC_66B74E37DD9E

#include <mars/core/TestListener.h>

struct TestStatus : TestListener {
  TestStatus();
  bool successful() const;

private:
  void addFailure(const TestFailure&) override;

private:
  bool succ;
};

#endif
