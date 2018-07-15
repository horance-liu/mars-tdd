#ifndef HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6
#define HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6

#include <mars/core/TestCase.h>

template <typename Fixture>
struct TestMethod : TestCase {
private:
  using Method = void(Fixture::*)();

public:
  TestMethod(Method method)
    : method(method) {}

private:
  void setUp() override {
    fixture.setUp();
  }

  void runTest() override {
    (self.*method)();
  }

  void tearDown() override {
    fixture.tearDown();
  }

private:
  Fixture self;
  Method method;
  TestFixture& fixture = self;
};

#endif
