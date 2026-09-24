#pragma once
#include "expression.hpp"

class NullExpression : public Expression {
public:
	~NullExpression() {}
	double result();
};
