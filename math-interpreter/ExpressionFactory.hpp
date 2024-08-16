#pragma once
#include "NullExpression.hpp"
#include "Number.hpp"
#include "Operation.hpp"
#include "Function.hpp"
#include <memory>

class ExpressionFactory
{
public:
    static std::shared_ptr<Expression> create(const std::string& input_expression)
	{
		if (!check_brackets(input_expression))
		{
			std::cout << "ERROR invalid brackets, returning null expression" << std::endl;
			return std::make_shared<NullExpression>();
		}
		if (auto expr = split_for_adding_or_substracting(input_expression); typeid(*expr) != typeid(NullExpression))
		{
			return expr;
		}
        if (auto expr = split_for_multiplying_or_dividing(input_expression); typeid(*expr) != typeid(NullExpression))
		{
			return expr;
		}
		if (auto expr = prepare_function(input_expression); typeid(*expr) != typeid(NullExpression))
		{
			return expr;
		}
		if (auto expr = check_if_only_number_left(input_expression); typeid(*expr) != typeid(NullExpression))
		{
			return expr;
		}
		if (input_expression.front() == '(' && input_expression.back() == ')')
		{
			return create(input_expression.substr(1, input_expression.length() - 2));
		}
		return std::make_shared<Number>(0);
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
		if (bracket_depth == 0)
		{
			return true;
		}
		else
		{
			return false;
		}	
    }
	
	static std::shared_ptr<Expression> split_for_adding_or_substracting(const std::string& input_expression)
	{
		int bracket_depth = 0;
		for (size_t i = input_expression.size() - 1; i > 0; i--)
		{
			if (input_expression[i] == '(')
			{
				bracket_depth++;
			}
			else if (input_expression[i] == ')')
			{
				bracket_depth--;
			}
			if (bracket_depth == 0 && (input_expression[i] == '+' || input_expression[i] == '-'))
			{
				return std::make_shared<Operation>(input_expression[i],
													create(input_expression.substr(0, i)),
													create(input_expression.substr(i + 1, input_expression.length() -1)));
			}
		}
		return std::make_shared<NullExpression>();
	}

	static std::shared_ptr<Expression> split_for_multiplying_or_dividing(const std::string& input_expression)
	{
		int bracket_depth = 0;
		for (size_t i = input_expression.size() - 1; i > 0; i--)
		{
			if (input_expression[i] == '(')
			{
				bracket_depth++;
			}
			else if (input_expression[i] == ')')
			{
				bracket_depth--;
			}
			if (bracket_depth == 0 && (input_expression[i] == '*' || input_expression[i] == '/'))
			{
				return std::make_shared<Operation>(input_expression[i],
													create(input_expression.substr(0, i)),
													create(input_expression.substr(i + 1, input_expression.length() -1)));
			}
		}
		return std::make_shared<NullExpression>();
	}

	static std::shared_ptr<Expression> prepare_function(const std::string& input_expression)
	{
		std::unordered_set<std::string> function_names = Function::get_function_names();
		for (const std::string& function_name : function_names)
		{
			if (input_expression.compare(0, function_name.size(), function_name) == 0)
			{
				return std::make_shared<Function>(function_name, create(input_expression.substr(function_name.size() + 1, input_expression.size() - function_name.size() - 2)));
			}
		}
		return std::make_shared<NullExpression>();
	}

	static std::shared_ptr<Expression> check_if_only_number_left(const std::string& input_expression)
	{
        try 
        {
            double value = std::stod(input_expression);
            return std::make_shared<Number>(value);
        }
        catch (...)
        {
		    return std::make_shared<NullExpression>();
        }
	}
};
