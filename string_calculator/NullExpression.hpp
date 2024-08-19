#pragma once
#include "Expression.hpp"

class NullExpression : public Expression
{
public:
	NullExpression() {}
	~NullExpression() {}
	double result()
	{
		std::cout << "WARNING returning from null expression object" << std::endl;
		return 0;
	}
};
