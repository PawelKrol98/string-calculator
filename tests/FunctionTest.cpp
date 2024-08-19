#include <iostream>
#include <gtest/gtest.h>
#include "Function.hpp"
#include "Number.hpp"
#include "string"


std::shared_ptr<Expression> ptr(new Number(0));
class FunctionTests : public ::testing::Test
{
public:
    FunctionTests()
    {
        f = std::make_shared<Function>("sin", ptr);
    }
protected:
    std::shared_ptr<Function> f;
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
    std::shared_ptr<Number> n1(new Number(256));
    std::shared_ptr<Function> f1(new Function("sqrt", n1));
    std::shared_ptr<Function> f2(new Function("sqrt", f1));
    ASSERT_EQ(f2->result(), 4.0);
}
