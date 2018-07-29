#ifndef HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6
#define HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6

#include <mars/core/TestCase.h>
#include <mars/core/Method.h>

template <typename Fixture>
struct TestMethod : TestCase {
  TestMethod(Method<Fixture> method, const std::string& name = "")
    : TestCase(name), method(method) {}

private:
  void setUp() override {
    self = new Fixture;
    self->setUp();
  }

  void runTest() override {
    (self->*method)();
  }

  void tearDown() override {
    self->tearDown();
    delete self;
  }

private:
  Fixture* self = nullptr;
  Method<Fixture> method;
};

#endif
