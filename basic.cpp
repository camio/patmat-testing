#include <iostream>
#include <gtest/gtest.h>

enum class NumberClass {
    Negative,
    Zero,
    Positive
};

NumberClass numberClassOf(int i) {
    inspect(i) {
        0            : return NumberClass::Zero;
        i if (i > 0) : return NumberClass::Positive;
        __           : return NumberClass::Negative;
    }
}

// Verify pattern guards without using lookup of bound identifiers
GTEST_TEST(Patmat,NumberClass)
{
    EXPECT_EQ(NumberClass::Negative,numberClassOf(-1));
    EXPECT_EQ(NumberClass::Zero,numberClassOf(0));
    EXPECT_EQ(NumberClass::Positive,numberClassOf(1));
}

int expressionTest(int i) {
    inspect(i) {
        3 : return 3;
        3+1 : return 4; // 3+1 is an expression
        __ : {return 5;} // statement wrapped in {}
    }
}

// Verify that normal c++ expressions are available for patterns
GTEST_TEST(Patmat,ExpressionTest)
{
    EXPECT_EQ(3,expressionTest(3));
    EXPECT_EQ(4,expressionTest(4));
    EXPECT_EQ(5,expressionTest(5));
    EXPECT_EQ(5,expressionTest(6));
    EXPECT_EQ(5,expressionTest(2));
}
