#include <mars/factory/TestSuiteFactory.h>
#include <mars/core/TestSuite.h>

TestSuiteFactory::TestSuiteFactory(const std::string& name)
  : name(name) {}

void TestSuiteFactory::add(TestFactory& f) {
  factories.push_back(&f);
}

Test* TestSuiteFactory::make() const {
  auto suite = new TestSuite(name);
  for (auto f : factories) {
    suite->add(f->make());
  }
  return suite;
}

TestSuiteFactory& TestSuiteFactory::root() {
  static TestSuiteFactory inst("All Tests");
  return inst;
}
