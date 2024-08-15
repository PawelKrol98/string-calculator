#pragma once
#include "NullExpression.hpp"
#include "Number.hpp"

class ExpressionFactory
{
public:
    static Expression* create(std::string input_expression)
	{
		if (!check_brackets(input_expression))
		{
			std::cout << "ERROR invalid brackets, returning null expression" << std::endl;
			return new NullExpression();
		}
		return new Number(3);
	}
private:
	static bool check_brackets(const std::string& input_expression)
	{
		int bracket_depth = 0;
		for (const char c : input_expression)
		{
			if (c == '(')
			{
				bracket_depth++;
			}
			else if (c == ')')
			{
				bracket_depth--;
				if (bracket_depth < 0) return false;
			}
		}
		return true;
	}
};
