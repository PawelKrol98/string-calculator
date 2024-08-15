#include <iostream>
#include <gtest/gtest.h>
#include "ExpressionFactory.hpp"
#include "NullExpression.hpp"

TEST(ExpressionFactoryTests, TestCorrectBrackets)
{
	EXPECT_FALSE(typeid(*ExpressionFactory::create("(1)+(1)")) == typeid(NullExpression));
    EXPECT_FALSE(typeid(*ExpressionFactory::create("(1)*((1)+(1))+(1)")) == typeid(NullExpression));
}

TEST(ExpressionFactoryTests, TestIncorrectBrackets)
{
	EXPECT_TRUE(typeid(*ExpressionFactory::create("(1))+(1)")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create(")((1)/(((3)))")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create("(2)-(1))")) == typeid(NullExpression));
	EXPECT_TRUE(typeid(*ExpressionFactory::create("((1)")) == typeid(NullExpression));
}

TEST(ExpressionFactoryTests, TestBasicNumber)
{
	auto exp = ExpressionFactory::create("10");
	EXPECT_EQ(exp->result(), 10.0);
}

TEST(ExpressionFactoryTests, TestNumberInBrackets)
{
	auto exp = ExpressionFactory::create("(11)");
	EXPECT_EQ(exp->result(), 11.0);
}

TEST(ExpressionFactoryTests, TestBasicAdding)
{
	auto exp = ExpressionFactory::create("2+2");
	EXPECT_EQ(exp->result(), 4.0);
}

TEST(ExpressionFactoryTests, TestBasicSubstracting)
{
	auto exp = ExpressionFactory::create("3-1");
    EXPECT_EQ(exp->result(), 2.0);
}

TEST(ExpressionFactoryTests, TestAddingAndSubstraction)
{
	auto exp = ExpressionFactory::create("2+3-1");
    EXPECT_EQ(exp->result(), 4.0);
}

TEST(ExpressionFactoryTests, TestTripleAdding)
{
	auto exp = ExpressionFactory::create("2+3+1");
    EXPECT_EQ(exp->result(), 6.0);
}

TEST(ExpressionFactoryTests, TestTripleSubstracting)
{
	auto exp = ExpressionFactory::create("2-3-1");
    EXPECT_EQ(exp->result(), -2.0);
}

TEST(ExpressionFactoryTests, TestAddingBrackets)
{
	auto exp = ExpressionFactory::create("(7-3)+(2-1)");
    EXPECT_EQ(exp->result(), 5.0);
}

TEST(ExpressionFactoryTests, TestBasicMultiplying)
{
	auto exp = ExpressionFactory::create("2*2");
	EXPECT_EQ(exp->result(), 4.0);
}

TEST(ExpressionFactoryTests, TestBasicDividing)
{
	auto exp = ExpressionFactory::create("10/4");
	EXPECT_EQ(exp->result(), 2.5);
}
