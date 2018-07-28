#include <mars/auto/TestFactorySuite.h>
#include <mars/core/TestSuite.h>

void TestFactorySuite::addFactory(TestFactory& f) {
  factories.push_back(&f);
}

Test* TestFactorySuite::make() {
  auto suite = new TestSuite("All Tests");
  for (auto f : factories) {
    suite->add(f->make());
  }
  return suite;
}
