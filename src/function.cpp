#include "string_calculator/string_calculator.hpp"

std::unordered_set<std::string> Function::get_function_names() {
    std::unordered_set<std::string> function_names = {};
    for (const auto& function : function_map) {
        function_names.insert(function.first);
    }
    return function_names;
}

double Function::result() {
    //std::cout << "DEBUG executing function " << function_name_ << std::endl;
    auto selected_function = function_map.at(function_name_);
    return selected_function(argument_);
}
