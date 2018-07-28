#ifndef H5D369611_C7D5_4E64_AD1A_0C7295CD030F
#define H5D369611_C7D5_4E64_AD1A_0C7295CD030F

struct Test;

struct TestFactory {
  virtual Test* make() = 0;
  virtual ~TestFactory() {}
};

#endif
