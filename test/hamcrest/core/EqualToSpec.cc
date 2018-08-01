#include <gtest/gtest.h>
#include <hamcrest/core/EqualTo.h>

TEST(EqualToSpec, equals_to) {
  EqualTo<int> m(32);
  ASSERT_TRUE(m(32));
  ASSERT_FALSE(m(33));

  ASSERT_TRUE(m(' '));
}
