#ifndef HC4BEBBE9_6C0F_4E85_9E97_A62AD0EAB58F
#define HC4BEBBE9_6C0F_4E85_9E97_A62AD0EAB58F

struct Test;

struct TestFactory {
  virtual Test* make() = 0;
  virtual ~TestFactory() {}
};

#endif
