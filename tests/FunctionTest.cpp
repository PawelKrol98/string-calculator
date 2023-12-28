#include <iostream>
#include <gtest/gtest.h>
#include "Function.hpp"

class FunctionTests : public ::testing::Test
{
public:
protected:
    Function f;
};

TEST_F(FunctionTests, TestDefaultFunctionNames)
{
    std::unordered_set<std::string> fnames = {"sqrt", "cos", "sin"};
    ASSERT_EQ(Function::get_function_names(), fnames);
}

TEST_F(FunctionTests, TestDefaultFunctionSizess)
{
    ASSERT_EQ(Function::get_function_names().size(), 3);
}