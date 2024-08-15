#include <iostream>
#include <gtest/gtest.h>
#include "Function.hpp"
#include "Number.hpp"
#include "Operation.hpp"
#include "string"
#include <memory>


std::shared_ptr<Expression> ptr5(new Number(5.0));
std::shared_ptr<Expression> ptr3(new Number(3.0));
class OperationTests : public ::testing::Test
{
};

TEST_F(OperationTests, TestAdd)
{
    std::shared_ptr<Operation> o(new Operation('+', ptr5, ptr3));
    ASSERT_EQ(o->result(), 8.0);
}

TEST_F(OperationTests, TestSubstraction)
{
    std::shared_ptr<Operation> o(new Operation('-', ptr5, ptr3));
    ASSERT_EQ(o->result(), 2.0);
}

TEST_F(OperationTests, TestMultiply)
{
    std::shared_ptr<Operation> o(new Operation('*', ptr5, ptr3));
    ASSERT_EQ(o->result(), 15.0);
}

TEST_F(OperationTests, TestDivide)
{
    std::shared_ptr<Operation> o(new Operation('/', ptr5, ptr3));
    ASSERT_EQ(o->result(), 5.0/3.0);
}

TEST_F(OperationTests, TestInternalOperations)
{
    std::shared_ptr<Operation> o1(new Operation('+', ptr5, ptr3));
    std::shared_ptr<Operation> o2(new Operation('-', ptr5, ptr3));
    std::shared_ptr<Operation> o3(new Operation('*', o1, o2));
    ASSERT_EQ(o3->result(), 16.0);
}