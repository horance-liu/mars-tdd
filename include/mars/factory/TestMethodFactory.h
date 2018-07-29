#ifndef HE3489549_5145_4E08_A9FB_8B342983AA3F
#define HE3489549_5145_4E08_A9FB_8B342983AA3F

#include <mars/factory/TestFactory.h>
#include <mars/core/TestMethod.h>
#include <mars/util/TypeName.h>

template <typename Fixture>
struct TestMethodFactory : TestFactory {
  TestMethodFactory(const char* name, Method<Fixture> method)
    : name(name), method(method) {}

private:
  Test* make() override {
    return new TestMethod<Fixture>(method, name);
  }

private:
  const char* name;
  Method<Fixture> method;
};

#endif
