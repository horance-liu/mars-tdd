#ifndef HB058FB8E_682E_4DED_9EBB_23DDB3710DD1
#define HB058FB8E_682E_4DED_9EBB_23DDB3710DD1

#include <string>

struct TestFailure {
  TestFailure(const char* name, std::string&& msg, bool failure);

  const char* getTestName() const;
  bool isFailure() const;
  const std::string& getExceptionMsg() const;

private:
  const char* name;
  std::string msg;
  bool failure;
};

#endif
