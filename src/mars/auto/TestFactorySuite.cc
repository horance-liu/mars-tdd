#include <mars/auto/TestFactorySuite.h>
#include <mars/core/TestSuite.h>

template <typename F>
void TestFactorySuite::foreach(F f) const {
  for (auto factory : factories) {
    f(factory);
  }
}

TestFactorySuite::~TestFactorySuite() {
  foreach([](auto f){
    delete f;
  });
}

void TestFactorySuite::addFactory(TestFactory* f) {
  factories.push_back(f);
}

Test* TestFactorySuite::make() {
  auto suite = new TestSuite("All Tests");
  foreach([suite](auto f){
    suite->add(f->make());
  });
  return suite;
}
