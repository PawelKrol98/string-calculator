#pragma once
#include "Expression.hpp"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>

class Function : public Expression
{
private:
    inline const static std::unordered_map<std::string, std::function<double(Expression*)>> function_map =
    {
        {"sin", [](Expression* ex) { return std::sin(ex->result()); }},
        {"cos", [](Expression* ex) { return std::cos(ex->result()); }},
        {"sqrt", [](Expression* ex) { return std::sqrt(ex->result()); }}
    };
    std::string function_name;
    Expression* argument;

public:
    Function(std::string _function_name, Expression* _argument) : function_name(_function_name), argument(_argument) {}

    ~Function()
    {
        delete argument;
    }

    static std::unordered_set<std::string> get_function_names()
    {
        std::unordered_set<std::string> function_names = {};
        for (const auto& function : function_map)
        {
            //std::cout << function.first << std::endl;
            function_names.insert(function.first);
        }
        return function_names;
    }

    double result() override
    {
        auto selected_function = function_map.at(function_name);
        return selected_function(argument);
    }
};
