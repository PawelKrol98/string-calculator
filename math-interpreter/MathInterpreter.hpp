#pragma once
#include <unordered_map>
#include <functional>
#include <string>
#include "Expression.hpp"
#include <optional>
#include <vector>
#include "Function.hpp"

class MathInterpreter
{
private:
    std::unordered_map<std::string, double> variable_map;

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
        //std::cout << lefthand_side << "=" << righthand_side << std::endl;
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
                //std::cout << lefthand_side << " " << function_name << std::endl;
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

    double calculate(const std::string& expression) const
    {
        if (expression.empty())  
        {
            return 0;
        }
        return 0;
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
};
