#ifndef HF44323E1_B8AD_4237_8BD4_6DFB4AF93BDD
#define HF44323E1_B8AD_4237_8BD4_6DFB4AF93BDD

#include <mars/util/StaticAssert.h>

template<typename From, typename To>
struct StructWrapper : From {
  static const To& by(const From& from) {
    STATIC_ASSERT(sizeof(From) == sizeof(To));
    return (const To&) from;
  }

  static To& by(From& from) {
    STATIC_ASSERT(sizeof(From) == sizeof(To));
    return (To&) from;
  }
};

#define STRUCT_WRAPPER(To, From) \
  struct To : StructWrapper<From, To>

#endif
