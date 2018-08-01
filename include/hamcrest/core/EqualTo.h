#ifndef H08C71F2F_A432_4E07_833B_A5241BA99253
#define H08C71F2F_A432_4E07_833B_A5241BA99253

template <typename T>
struct EqualTo {
  explicit EqualTo(const T& rhs) : rhs(rhs) {}

  template <typename U>
  bool operator()(const U& lhs) const {
    return lhs == rhs;
  }

private:
  T rhs;
};

#endif
