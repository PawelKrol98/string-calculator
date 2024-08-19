#pragma once
#include <unordered_map>
#include <functional>
#include <string>
#include "Expression.hpp"
#include "ExpressionFactory.hpp"
#include <optional>
#include <vector>
#include "Function.hpp"

class MathInterpreter
{

public:
    MathInterpreter()
    {
        declare_variable("pi=3.14159265359");
        declare_variable("e=2.71828182845");
    }

    bool declare_variable(const std::string& assigment)
    {
        int equal_sing_pos = assigment.find("=");
        if (equal_sing_pos == std::string::npos)
        {
            return false;
        }
        std::string lefthand_side = assigment.substr(0, equal_sing_pos);
        std::string righthand_side = assigment.substr(equal_sing_pos + 1, assigment.size() - equal_sing_pos );
        lefthand_side.erase(std::remove_if(lefthand_side.begin(), lefthand_side.end(), ::isspace), lefthand_side.end());
        righthand_side.erase(std::remove_if(righthand_side.begin(), righthand_side.end(), ::isspace), righthand_side.end());
        if (!std::all_of(lefthand_side.begin(), lefthand_side.end(), [](char c) { return std::isalpha(c); }))
        {
            return false;
        }
        if (!std::all_of(righthand_side.begin(), righthand_side.end(), [](char c) { return std::isdigit(c) or c=='.'; }) or
            std::count(righthand_side.begin(), righthand_side.end(), '.') > 1)
        {
            return false;
        }
        for (const auto& function_name : Function::get_function_names())
        {
            if (lefthand_side == function_name)
            {
                return false;
            }
        }
        variable_map.insert({lefthand_side, std::stod(righthand_side)});
        return true;
    }

    std::vector<std::string> get_variable_names() const
    {
        std::vector<std::string> variable_names = {};
        for (const auto& variable : variable_map)
        {
            variable_names.push_back(variable.first);
        }
        return variable_names;
    }

	void correct_expression(std::string& input_expression) const
	{
		input_expression.erase(std::remove(input_expression.begin(), input_expression.end(), ' '), input_expression.end());
        for (const auto& variable : variable_map)
        {
            replace_variable(input_expression, variable.first, variable.second);
        }
        insert_between_operators(input_expression);
        correct_brackets(input_expression);
	}

    double calculate(std::string expression) const
    {
        if (expression.empty())  
        {
            return 0;
        }
		correct_expression(expression);
		std::shared_ptr<Expression> expr = ExpressionFactory::create(expression);
        return expr->result();
    }

    std::optional<double> get_variable(const std::string& variable_name) const
    {
        auto it = variable_map.find(variable_name);
        if (it != variable_map.end()) 
        {
            return it->second;
        } 
        else 
        {
            return std::nullopt;
        }
    }

private:
    std::unordered_map<std::string, double> variable_map;
    void replace_variable(std::string& input_expression, const std::string variable_name, double value) const
    {
        size_t pos = input_expression.find(variable_name);

        while (pos != std::string::npos) 
        {
            if (pos + variable_name.length() < input_expression.length() && !isalpha(input_expression[pos + variable_name.length()])) 
            {
                if (pos + variable_name.length() + 1 < input_expression.length() 
                    && input_expression[pos + variable_name.length() + 1] != '(' 
                    && input_expression[pos + variable_name.length() + 1] != ')') 
                {
                    input_expression.replace(pos, variable_name.length(), std::to_string(value));
                }
            }

            pos = input_expression.find(variable_name, pos + 1);
        }
    }

    void insert_between_operators(std::string& input_expression) const
    {
        std::string operators = "+-*/";

        if (!input_expression.empty() && operators.find(input_expression[0]) != std::string::npos)
        {
            if (input_expression[0] == '+' || input_expression[0] == '-')
            {
                input_expression.insert(0, "0");
            }
            else if (input_expression[0] == '*' || input_expression[0] == '/')
            {
                input_expression.insert(0, "1");
            }
        }
        for (size_t i = 0; i < input_expression.length() - 1; i++) 
        {
            if (operators.find(input_expression[i]) != std::string::npos &&
                operators.find(input_expression[i + 1]) != std::string::npos)
            {
                if (input_expression[i] == '+' || input_expression[i] == '-')
                {
                    input_expression.insert(i + 1, "0");
                }
                else if (input_expression[i] == '*' || input_expression[i] == '/')
                {
                    input_expression.insert(i + 1, "1");
                }
                i++;
            }
        }
    }

    void correct_brackets(std::string& input_expression) const
    {
        size_t i = 0;
        size_t length = input_expression.length();

        while (i < length)
        {
            if (input_expression[i] == '(' || input_expression[i] == ')')
            {
                if (i + 1 < length && input_expression[i] == '(' && input_expression[i + 1] == ')')
                {
                    input_expression.insert(i + 1, "0");
                    length++;
                    i++;
                }
                else if (i > 0 && std::isdigit(input_expression[i - 1]) && input_expression[i] == '(')
                {
                    input_expression.insert(i, "*");
                    length++;
                    i++;
                }
                else if (i + 1 < length && std::isdigit(input_expression[i + 1]) && input_expression[i] == ')')
                {
                    input_expression.insert(i + 1, "*");
                    length++;
                    i += 2; 
                }
                else if (i + 1 < length && input_expression[i] == ')' && input_expression[i + 1] == '(')
                {
                    input_expression.insert(i + 1, "*");
                    length++;
                    i += 2;
                }
            }
            i++;
        }
    }
    
};
