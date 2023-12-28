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
