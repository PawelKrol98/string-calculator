#include "string_calculator/null_expression.hpp"

double NullExpression::result() {
    std::cout << "WARNING returning from null expression object" << std::endl;
    return 0;
}
