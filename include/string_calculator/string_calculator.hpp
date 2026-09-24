#pragma once
#include <unordered_map>
#include <functional>
#include <string>
#include "expression.hpp"
#include "expression_factory.hpp"
#include <optional>
#include <vector>
#include "function.hpp"

class StringCalculator {

public:
    StringCalculator();
    bool declare_variable(const std::string& assigment);
    std::vector<std::string> get_variable_names() const;
	void correct_expression(std::string& input_expression) const;
    double calculate(std::string expression) const;
    std::optional<double> get_variable(const std::string& variable_name) const;

private:
    std::unordered_map<std::string, double> variable_map;
    void replace_variable(std::string& input_expression, const std::string variable_name, double value) const;
    void insert_between_operators(std::string& input_expression) const;
    void correct_brackets(std::string& input_expression) const;
};
