#ifndef H18DAD269_6DDC_436A_8E4E_9BC0D428E66A
#define H18DAD269_6DDC_436A_8E4E_9BC0D428E66A

#include <exception>
#include <string>

struct AssertionError : std::exception {
  AssertionError(const std::string& src, const std::string& msg);
};

#endif
