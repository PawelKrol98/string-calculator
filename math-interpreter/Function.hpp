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
    std::string function_name_;
    Expression* argument_;

public:
    Function(std::string function_name, Expression* argument) : function_name_(function_name), argument_(argument) {}

    ~Function()
    {
        delete argument_;
    }

    static std::unordered_set<std::string> get_function_names()
    {
        std::unordered_set<std::string> function_names = {};
        for (const auto& function : function_map)
        {
            function_names.insert(function.first);
        }
        return function_names;
    }

    double result() override
    {
		std::cout << "DEBUG executing function " << function_name_ << std::endl;
        auto selected_function = function_map.at(function_name_);
        return selected_function(argument_);
    }
};
