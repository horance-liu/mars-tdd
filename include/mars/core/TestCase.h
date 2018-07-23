#ifndef H93A07344_57E2_4859_A5F8_8394E57E38F5
#define H93A07344_57E2_4859_A5F8_8394E57E38F5

#include <mars/core/Test.h>
#include <mars/core/TestFixture.h>

struct TestCase : Test, private TestFixture {
  TestCase(const std::string& = "");
  const std::string& getName() const;

private:
  void run() override;

private:
  virtual void runTest() {}

private:
  std::string name;
};

#endif
