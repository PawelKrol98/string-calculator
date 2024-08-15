#pragma once
#include "Expression.hpp"

class Number : public Expression
{
private:
    double value;
    
public:
    Number(double _value)  : value(_value) {}
    ~Number() {}

    double result() override
    {
		std::cout << "DEBUG executing number " << value << std::endl;
        return value;
    }
};
