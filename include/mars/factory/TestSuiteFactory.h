#ifndef H778D6461_5C14_48E4_9EF2_B343DAAEC3DF
#define H778D6461_5C14_48E4_9EF2_B343DAAEC3DF

#include <mars/factory/TestFactory.h>
#include <vector>
#include <string>

struct TestSuiteFactory : TestFactory {
  explicit TestSuiteFactory(const std::string&);
  void add(TestFactory&);

  static TestSuiteFactory& root();

protected:
  Test* make() override;

private:
  std::string name;
  std::vector<TestFactory*> factories;
};


#endif
