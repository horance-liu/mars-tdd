#ifndef HD8618907_277F_4C12_B2F4_F57CF881058B
#define HD8618907_277F_4C12_B2F4_F57CF881058B

#include <mars/auto/AutoTestMethod.h>
#include <mars/util/Symbol.h>

#define __TEST_NAME(id) JOIN(test_, id)
#define __AUTO_TEST(id) JOIN(auto_test_, id)

#define __DEF_TEST(id, name)              \
private:                                  \
AutoTestMethod __AUTO_TEST(id)             \
  {id, name, &self_type::__TEST_NAME(id)}; \
public:                                   \
void __TEST_NAME(id)()

#define TEST(name) __DEF_TEST(UNIQUE_ID, name)

#endif
