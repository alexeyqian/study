#include <gtest/gtest.h>

TEST(Tuples, a_tuple_with_w_equals_1_is_a_point){
    //auto& a = Tuple(4.3, -4.2, 3.1, 1.0);
    //ASSERT_EQ(4.3, a.x);
    //...
    // and a is a point
    // and a is not a vector
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}