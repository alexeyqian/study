// tests.cpp
#include "../src/sqrt.cpp"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}

TEST(Tuples, a_tuple_with_w_equals_1_is_a_point){
    auto& a = Tuple(4.3, -4.2, 3.1, 1.0);
    ASSERT_EQ(4.3, a.x);
    //...
    // and a is a point
    // and a is not a vector
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}