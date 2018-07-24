#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/core/internal/TestCaseFunctor.h>

namespace {
  struct Functor : TestCaseFunctor {
    using Method = void(TestCase::*)();

    Functor(TestCase* self, Method method, const char* place)
      : self(self), method(method), place(place) {
    }

  private:
    const char* where() const override {
      return place;
    }

    bool operator()() const override {
      (self->*method)();
      return true;
    }

  private:
    TestCase* self;
    Method method;
    const char* place;
  };
}

#define PROTECT(method) \
  result.protect(Functor(this, &TestCase::method,  "in the "#method))

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
