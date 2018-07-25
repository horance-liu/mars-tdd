#ifndef HB08C8360_B30F_410E_BE28_792BEE41206F
#define HB08C8360_B30F_410E_BE28_792BEE41206F

#include <vector>
#include <mars/core/TestListener.h>

struct TestFailure;

struct FailureLister : TestListener {
  template <typename F>
  void foreach(F f) const {
    for (auto failure : failures) {
      f(*failure);
    }
  }

private:
  void addFailure(const TestFailure&) override;

private:
  std::vector<const TestFailure*> failures;
};

#endif
