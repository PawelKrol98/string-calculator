#include "Function.hpp"

std::unordered_map<std::string, std::function<double(Expression*)>> Function::function_map = 
{
    {"sin", [](Expression* ex) { return std::sin(ex->result()); }},
    {"cos", [](Expression* ex) { return std::cos(ex->result()); }},
    {"sqrt", [](Expression* ex) { return std::sqrt(ex->result()); }}
};

Function::Function()
{
}

std::unordered_set<std::string> Function::get_function_names()
{
    std::unordered_set<std::string> function_names = {};
    for (const auto& function : function_map)
    {
        function_names.insert(function.first);
    }
    return function_names;
}

double Function::result()
{
    auto selected_function = function_map.at(function_name);
    return selected_function(argument);
}
