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
    MathInterpreter();
    bool declare_variable(const std::string&);
    std::vector<std::string> get_variable_names() const;
    double calculate(const std::string&) const;
    std::optional<double> get_variable(const std::string&) const;
};
