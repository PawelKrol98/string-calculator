#pragma once
#include "Expression.hpp"

class Number : public Expression
{
private:
    double value_;
    
public:
    Number(double value)  : value_(value) {}
    ~Number() {}

    double result() override
    {
		std::cout << "DEBUG executing number " << value_ << std::endl;
        return value_;
    }
};
