#pragma once
#include "expression.hpp"

class Number : public Expression {
private:
    double value_;
    
public:
    Number(double value)  : value_(value) {}
    ~Number() {}

    double result() override;
};
