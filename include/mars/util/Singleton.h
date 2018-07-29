#ifndef H355789B7_673B_442E_BCB7_8FFBCB683E48
#define H355789B7_673B_442E_BCB7_8FFBCB683E48

#include <mars/util/Symbol.h>

template<typename T>
struct Singleton {
  static T& instance() {
    static T inst;
    return inst;
  }

protected:
  Singleton() {}
};

#define SINGLETON(type) \
  struct type : Singleton<type>

#define GENERIC_SINGLETON(type, ...)         \
  template<typename __VA_ARGS__>             \
  struct type : Singleton<type<__VA_ARGS__>>

#endif
