#include <iostream>
#include <gtest/gtest.h>
#include "MathInterpreter.hpp"

class MathInterpreterTests : public ::testing::Test
{
public:
protected:
    MathInterpreter mi;
};

TEST_F(MathInterpreterTests, TestEmptyExpression)
{
    ASSERT_EQ(mi.calculate(""), 0);
}

TEST_F(MathInterpreterTests, TestGetPi)
{
    ASSERT_EQ(mi.get_variable("pi"), 3.14159265359);
}

TEST_F(MathInterpreterTests, TestDeclareX)
{
    ASSERT_TRUE(mi.declare_variable("X=5"));
}

TEST_F(MathInterpreterTests, TestDeclareXEqual5)
{
    ASSERT_TRUE(mi.declare_variable("X=5"));
    ASSERT_EQ(mi.get_variable("X").value(), 5.0);
}

TEST_F(MathInterpreterTests, TestGetNoExistingVar)
{
    ASSERT_FALSE(mi.get_variable("X").has_value());
}

TEST_F(MathInterpreterTests, TestDeclareWithNoEQualSign)
{
    ASSERT_FALSE(mi.declare_variable("X5"));
}

TEST_F(MathInterpreterTests, TestDeclareWithTwoEQualSign)
{
    ASSERT_FALSE(mi.declare_variable("X==5"));
}

TEST_F(MathInterpreterTests, TestDeclareXWithDot)
{
    ASSERT_TRUE(mi.declare_variable("X=5.0"));
}

TEST_F(MathInterpreterTests, TestDeclareXWith2Dots)
{
    ASSERT_FALSE(mi.declare_variable("X=5..0"));
}

TEST_F(MathInterpreterTests, TestDeclareLHSWithNumber)
{
    ASSERT_FALSE(mi.declare_variable("X1=5"));
}

TEST_F(MathInterpreterTests, TestDeclareRHSWithSign)
{
    ASSERT_FALSE(mi.declare_variable("X=5?"));
}

TEST_F(MathInterpreterTests, TestDeclareRHSWithLetter)
{
    ASSERT_FALSE(mi.declare_variable("X=5X"));
}

TEST_F(MathInterpreterTests, TestDeclareSinName)
{
    ASSERT_FALSE(mi.declare_variable("sin=2"));
    ASSERT_EQ(mi.get_variable_names().size(), 2);
}

TEST_F(MathInterpreterTests, TestBasicVariablesDeclaration)
{
    std::vector<std::string> vnames = {"e", "pi"};
    ASSERT_EQ(mi.get_variable_names().size(), vnames.size());
    for (int i = 0; i < mi.get_variable_names().size(); i++)
    {
        EXPECT_EQ(mi.get_variable_names()[i], vnames[i]);
    }
}

TEST_F(MathInterpreterTests, TestDeclareVariableIncreaseSize)
{
    ASSERT_EQ(mi.get_variable_names().size(), 2);
    mi.declare_variable("X=5");
    ASSERT_EQ(mi.get_variable_names().size(), 3);
    mi.declare_variable("X===5");
    ASSERT_EQ(mi.get_variable_names().size(), 3);
}

TEST_F(MathInterpreterTests, TestVariablesCorrecting)
{
	mi.declare_variable("x=3");
	mi.declare_variable("y=5");
	std::string my_expr = "x+y+pi+4";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3.000000+5.000000+3.141593+4");
}

TEST_F(MathInterpreterTests, TestRemoveSpaces)
{
	std::string my_expr = "2 + 7 +   1 - (50)";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "2+7+1-(50)");
}

TEST_F(MathInterpreterTests, TestFillDoubleAddOperand)
{
	std::string my_expr = "2++1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "2+0+1");
}

TEST_F(MathInterpreterTests, TestFillDoubleSubstractOperand)
{
	std::string my_expr = "3--1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3-0-1");
}

TEST_F(MathInterpreterTests, TestFillTripleSubstractOperand)
{
	std::string my_expr = "3---1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3-0-0-1");
}

TEST_F(MathInterpreterTests, TestFillDoubleMultiplyOperand)
{
	std::string my_expr = "3**1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3*1*1");
}

TEST_F(MathInterpreterTests, TestFillDoubleDividingOperand)
{
	std::string my_expr = "3//1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3/1/1");
}

TEST_F(MathInterpreterTests, TestFillAddAndSubstractOperand)
{
	std::string my_expr = "3+-1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3+0-1");
}

TEST_F(MathInterpreterTests, TestFillMultiplyAndAddOperand)
{
	std::string my_expr = "3*+1";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "3*1+1");
}

TEST_F(MathInterpreterTests, TestFillMinusNumber)
{
	std::string my_expr = "-34";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "0-34");
}

TEST_F(MathInterpreterTests, TestFillDivideNumber)
{
	std::string my_expr = "/34";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "1/34");
}

TEST_F(MathInterpreterTests, TestFillEmptyBracket)
{
	std::string my_expr = "()";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "(0)");
}

TEST_F(MathInterpreterTests, TestFillMultiplyBracket)
{
	std::string my_expr = "4(2+4)";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "4*(2+4)");
}

TEST_F(MathInterpreterTests, TestFillMultiplyBrackeOpposite)
{
	std::string my_expr = "(2+4)*3";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "(2+4)*3");
}

TEST_F(MathInterpreterTests, TestFillMultiplyBrackets)
{
	std::string my_expr = "(4+4/2)(2+4)";
	mi.correct_expression(my_expr);
	EXPECT_EQ(my_expr, "(4+4/2)*(2+4)");
}

TEST_F(MathInterpreterTests, TestBasicOperation)
{
	EXPECT_EQ(mi.calculate("2+2"), 4.0);
}


TEST_F(MathInterpreterTests, TestBasicNumber)
{
	EXPECT_EQ(mi.calculate("2"), 2.0);
}

TEST_F(MathInterpreterTests, TestBasicFunction)
{
	EXPECT_EQ(mi.calculate("sqrt(625)"), 25.0);
}

TEST_F(MathInterpreterTests, TestComplexOperation)
{
	EXPECT_EQ(mi.calculate("/6+2(8*4-3)/(sqrt(()+12*12))"), 5.0);
}