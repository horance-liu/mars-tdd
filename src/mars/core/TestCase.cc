#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/core/internal/TestCaseFunctor.h>

namespace {
  struct Functor : TestCaseFunctor {
    using Method = void(TestCase::*)();

    Functor(TestCase* self, Method method)
      : self(self), method(method) {
    }

  private:
    bool operator()() const override {
      (self->*method)();
      return true;
    }

  private:
    TestCase* self;
    Method method;
  };
}

#define PROTECT(method) result.protect(Functor(this, &TestCase::method))

void TestCase::runBare(TestResult& result) {
  if (PROTECT(setUp)) {
    PROTECT(runTest);
  }
  PROTECT(tearDown);
}

void TestCase::run(TestResult& result) {
  result.startTestCase();
  runBare(result);
}

int TestCase::countTestCases() const {
  return 1;
}
