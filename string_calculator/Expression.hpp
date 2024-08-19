#pragma once
#include <iostream>

class Expression
{
public:
    virtual double result() = 0;
    virtual ~Expression()
    {
    }
};
