#include <iostream>
#include <gtest/gtest.h>
#include "ExpressionFactory.hpp"
#include "NullExpression.hpp"

TEST(ExpressionFactoryTests, TestCorrectBrackets)
{
	EXPECT_FALSE(typeid(*ExpressionFactory::create("(1)+(1)")) == typeid(NullExpression));
    EXPECT_FALSE(typeid(*ExpressionFactory::create("(1)+((1)+(1))+(1)")) == typeid(NullExpression));
}

TEST(ExpressionFactoryTests, TestIncorrectBrackets)
{
	EXPECT_TRUE(typeid(*ExpressionFactory::create("(1)+)(1)")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create(")((1)*(((1)))")) == typeid(NullExpression));
    EXPECT_TRUE(typeid(*ExpressionFactory::create("(1)+(1))")) == typeid(NullExpression));
	EXPECT_TRUE(typeid(*ExpressionFactory::create("((1)-1")) == typeid(NullExpression));
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

TEST(ExpressionFactoryTests, TestTripleMultiplying)
{
	auto exp = ExpressionFactory::create("2*5*60");
	EXPECT_EQ(exp->result(), 600.0);
}

TEST(ExpressionFactoryTests, TestTripleDividing)
{
	auto exp = ExpressionFactory::create("100/5/4");
	EXPECT_EQ(exp->result(), 5.0);
}

TEST(ExpressionFactoryTests, TestMutliplyingAndDividing)
{
	auto exp = ExpressionFactory::create("15/3*20/5");
	EXPECT_EQ(exp->result(), 20.0);
}

TEST(ExpressionFactoryTests, TestAddingMultiplying)
{
	auto exp = ExpressionFactory::create("2*3+6*1");
	EXPECT_EQ(exp->result(), 12.0);
}

TEST(ExpresisonFactoryTests, TestSubstractingDividing)
{
	auto exp = ExpressionFactory::create("30/5-40/20");
	EXPECT_EQ(exp->result(), 4.0);
}

TEST(ExpresisonFactoryTests, TestBasicFunction)
{
	auto exp = ExpressionFactory::create("sqrt(4)");
	EXPECT_EQ(exp->result(), 2.0);
}

TEST(ExpresisonFactoryTests, TestFunctionInFunction)
{
	auto exp = ExpressionFactory::create("sqrt(sqrt(256))");
	EXPECT_EQ(exp->result(), 4.0);
}

TEST(ExpresisonFactoryTests, TestAddingFunctions)
{
	auto exp = ExpressionFactory::create("sqrt(4)+sqrt(100)");
	EXPECT_EQ(exp->result(), 12.0);
}

TEST(ExpresisonFactoryTests, TestSubstractingFunctions)
{
	auto exp = ExpressionFactory::create("sqrt(100)-sqrt(64)");
	EXPECT_EQ(exp->result(), 2.0);
}

TEST(ExpresisonFactoryTests, TestSubstractingInsideFunction)
{
	auto exp = ExpressionFactory::create("sqrt(sqrt(100)-sqrt(36))");
	EXPECT_EQ(exp->result(), 2.0);
}
