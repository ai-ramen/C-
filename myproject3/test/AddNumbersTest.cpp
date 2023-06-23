#include <iostream>
#include <gtest/gtest.h>

extern "C" {
    int add(int a, int b);
}

TEST(AdditionTest, PositiveNumbers) {
    int num1 = 5;
    int num2 = 10;
    int expectedSum = 15;
    int sum = add(num1, num2);
    
    ASSERT_EQ(expectedSum, sum);
}

TEST(AdditionTest, NegativeNumbers) {
    int num1 = -5;
    int num2 = -10;
    int expectedSum = -15;
    int sum = add(num1, num2);
    
    ASSERT_EQ(expectedSum, sum);
}

// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }