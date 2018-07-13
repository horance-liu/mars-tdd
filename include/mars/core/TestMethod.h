#ifndef HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6
#define HD3E38C9A_3B03_48CE_9A1B_75B41CB012C6

template <typename Fixture>
struct TestMethod {
private:
  using Method = void(Fixture::*)();

public:
  TestMethod(Method method)
    : method(method) {}

  void run() {
    (self.*method)();
  }

private:
  Fixture self;
  Method method;
};

#endif
