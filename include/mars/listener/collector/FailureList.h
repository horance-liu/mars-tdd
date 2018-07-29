#ifndef HB08C8360_B30F_410E_BE28_792BEE41206F
#define HB08C8360_B30F_410E_BE28_792BEE41206F

#include <vector>
#include <mars/core/TestListener.h>
#include <mars/except/TestFailure.h>

struct TestFailure;

struct FailureList : TestListener {
  template <typename F>
  void foreach(F f) const {
    for (auto failure : failures) {
      f(*failure);
    }
  }

  void addFailure(const TestFailure&) override;

private:
  std::vector<const TestFailure*> failures;
};

#endif
