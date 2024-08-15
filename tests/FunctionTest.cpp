#include <iostream>
#include <gtest/gtest.h>
#include "Function.hpp"
#include "Number.hpp"
#include "string"


Number zero = Number(0);
Expression* ptr = &zero;
class FunctionTests : public ::testing::Test
{
public:
    FunctionTests()
    {
        f = new Function("sin", ptr);
    }
protected:
    Function* f;
};

TEST_F(FunctionTests, TestDefaultFunctionNames)
{
    std::unordered_set<std::string> fnames = {"sqrt", "cos", "sin"};
    ASSERT_EQ(Function::get_function_names(), fnames);
}

TEST_F(FunctionTests, TestDefaultFunctionSizes)
{
    ASSERT_EQ(Function::get_function_names().size(), 3);
}

TEST_F(FunctionTests, TestSin0return0)
{
    ASSERT_EQ(f->result(), 0.0);
}

TEST_F(FunctionTests, TestInternalFunction)
{
    Number* n1 = new Number(256);
    Function* f1 = new Function("sqrt", n1);
    Function* f2 = new Function("sqrt", f1);
    ASSERT_EQ(f2->result(), 4.0);
}