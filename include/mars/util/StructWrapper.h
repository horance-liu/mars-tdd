#ifndef HF44323E1_B8AD_4237_8BD4_6DFB4AF93BDD
#define HF44323E1_B8AD_4237_8BD4_6DFB4AF93BDD

template<typename From, typename To>
struct StructWrapper: protected From {

  static const To& by(const From& from) {
    static_assert(sizeof(From) == sizeof(To), "");
    return (const To&) from;
  }

  static To& by(From& from) {
    static_assert(sizeof(From) == sizeof(To), "");
    return (To&) from;
  }
};

#define STRUCT_WRAPPER(To, From) \
  struct To : StructWrapper<From, To>

#endif
