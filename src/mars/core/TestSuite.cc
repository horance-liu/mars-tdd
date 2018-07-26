#include <mars/core/TestSuite.h>
#include <mars/core/TestResult.h>

void TestSuite::add(Test* test) {
  tests.push_back(test);
}

template <typename F>
inline void TestSuite::foreach(F f) const {
  for (auto test : tests) {
    f(test);
  }
}

TestSuite::~TestSuite() {
  foreach([](auto test) {
    delete test;
  });
}

void TestSuite::runBare(TestResult& result) {
  foreach([&result](auto test) {
    test->run(result);
  });
}

const Test& TestSuite::get() const {
  return *this;
}

void TestSuite::run(TestResult& result) {
  result.runTestSuite(*this);
}

template <typename Init, typename F>
inline Init TestSuite::reduce(Init init, F f) const {
  foreach([&init, f](auto test) {
    init += f(test);
  });
  return init;
}

int TestSuite::countTestCases() const {
  return reduce(0, [](auto test){
    return test->countTestCases();
  });
}
