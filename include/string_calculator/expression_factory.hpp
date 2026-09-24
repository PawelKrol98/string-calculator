#pragma once
#include "null_expression.hpp"
#include "number.hpp"
#include "operation.hpp"
#include "function.hpp"
#include <memory>

class ExpressionFactory {
public:
    static std::shared_ptr<Expression> create(const std::string& input_expression);
private:
	static bool check_brackets(const std::string& input_expression);
	static std::shared_ptr<Expression> split_for_adding_or_substracting(const std::string& input_expression);
	static std::shared_ptr<Expression> split_for_multiplying_or_dividing(const std::string& input_expression);
	static std::shared_ptr<Expression> prepare_function(const std::string& input_expression);
	static std::shared_ptr<Expression> check_if_only_number_left(const std::string& input_expression);
};
