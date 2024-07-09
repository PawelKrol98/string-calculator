#pragma once
#include "Expression.hpp"

class ExpressionFactory
{
public:
    static Expression* create(std::string);
};