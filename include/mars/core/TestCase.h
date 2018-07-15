#ifndef H93A07344_57E2_4859_A5F8_8394E57E38F5
#define H93A07344_57E2_4859_A5F8_8394E57E38F5

#include <mars/core/TestFixture.h>

struct TestCase : private TestFixture {
  void run();

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}
};

#endif
