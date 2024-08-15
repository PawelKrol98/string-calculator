#include <iostream>
#include <gtest/gtest.h>
#include "ExpressionFactory.hpp"
#include "NullExpression.hpp"

TEST(ExpressionFactoryTests, TestCorrectBrackets)
{
	EXPECT_FALSE(typeid(*ExpressionFactory::create("()()")) == typeid(NullExpression));
    EXPECT_FALSE(typeid(*ExpressionFactory::create("()(()())()")) == typeid(NullExpression));
}

TEST(ExpressionFactoryTests, TestIncorrectBrackets)
{
	EXPECT_TRUE(typeid(*ExpressionFactory::create("())()")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create(")(()((()))")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create("()())")) == typeid(NullExpression));
}

