#ifndef HB058FB8E_682E_4DED_9EBB_23DDB3710DD1
#define HB058FB8E_682E_4DED_9EBB_23DDB3710DD1

#include <string>

struct TestFailure {
  TestFailure(std::string&& msg, bool failure);

  bool isFailure() const;
  const std::string& getExceptionMsg() const;

private:
  std::string msg;
  bool failure;
};

#endif
