#include "gtest/gtest.h"
#include "../BigInt.h"

TEST(BigIntTest, ConstructorFromString) {
    BigInt num1("123");
    BigInt num2("-456");
    BigInt num3("0");

    EXPECT_EQ(std::string(num1), "123");
    EXPECT_EQ(std::string(num2), "-456");
    EXPECT_EQ(std::string(num3), "0");
}

TEST(BigIntTest, ConstructorFromInt) {
    BigInt num1(123);
    BigInt num2(-456);
    BigInt num3(0);

    EXPECT_EQ(std::string(num1), "123");
    EXPECT_EQ(std::string(num2), "-456");
    EXPECT_EQ(std::string(num3), "0");
}

TEST(BigIntTest, Addition) {
    BigInt num1("123");
    BigInt num2("456");
    BigInt result = num1 + num2;

    EXPECT_EQ(std::string(result), "579");
}

TEST(BigIntTest, Subtraction) {
    BigInt num1("1000");
    BigInt num2("123");
    BigInt result = num1 - num2;

    EXPECT_EQ(std::string(result), "877");
}

TEST(BigIntTest, Multiplication) {
    BigInt num1("12");
    BigInt num2("34");
    BigInt result = num1 * num2;

    EXPECT_EQ(std::string(result), "408");
}

TEST(BigIntTest, Comparison) {
    BigInt num1("100");
    BigInt num2("50");

    EXPECT_TRUE(num1 > num2);
    EXPECT_TRUE(num2 < num1);
    EXPECT_TRUE(num1 != num2);
}