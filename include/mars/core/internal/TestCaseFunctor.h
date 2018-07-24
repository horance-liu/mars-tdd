#ifndef H1EB32DF3_D891_4DF6_9A60_D1C5E1B6D092
#define H1EB32DF3_D891_4DF6_9A60_D1C5E1B6D092

struct TestCaseFunctor {
  virtual bool operator()() const = 0;
  virtual ~TestCaseFunctor() {}
};

#endif
