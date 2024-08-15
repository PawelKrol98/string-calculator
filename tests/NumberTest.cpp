#include <iostream>
#include <gtest/gtest.h>
#include "Number.hpp"
#include "string"


class NumberTests : public ::testing::Test
{
public:
    NumberTests()
    {
        n = new Number(1);
    }
protected:
    Number* n;
};

TEST_F(NumberTests, TestDefaultFunctionNames)
{
    ASSERT_EQ(n->result(), 1.0);
}