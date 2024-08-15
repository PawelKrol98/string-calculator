#include <iostream>
#include <gtest/gtest.h>
#include "Function.hpp"
#include "Number.hpp"
#include "Operation.hpp"
#include "string"


Number five = Number(5.0);
Number three = Number(3.0);
Expression* ptr5 = &five;
Expression* ptr3 = &three;
class OperationTests : public ::testing::Test
{
};

TEST_F(OperationTests, TestAdd)
{
    Operation* o = new Operation('+', ptr5, ptr3);
    ASSERT_EQ(o->result(), 8.0);
}

TEST_F(OperationTests, TestSubstraction)
{
    Operation* o = new Operation('-', ptr5, ptr3);
    ASSERT_EQ(o->result(), 2.0);
}

TEST_F(OperationTests, TestMultiply)
{
    Operation* o = new Operation('*', ptr5, ptr3);
    ASSERT_EQ(o->result(), 15.0);
}

TEST_F(OperationTests, TestDivide)
{
    Operation* o = new Operation('/', ptr5, ptr3);
    ASSERT_EQ(o->result(), 5.0/3.0);
}

TEST_F(OperationTests, TestInternalOperations)
{
    Operation* o1 = new Operation('+', ptr5, ptr3);
    Operation* o2 = new Operation('-', ptr5, ptr3);
    Operation* o3 = new Operation('*', o1, o2);
    ASSERT_EQ(o3->result(), 16.0);
}