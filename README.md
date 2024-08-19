## StringCalculator Library

The StringCalculator library is a C++ library designed to perform mathematical calculations from input strings. It provides a flexible and extensible way to evaluate mathematical expressions:

# Features:
 - String-based calculations: Evaluate mathematical expressions directly from strings.
 - Variable declaration: Declare and use variables within expressions.
 - Custom functions: Extend the library by defining your own mathematical functions.

# Installation

Clone the repository:
      
      git clone https://github.com/your-repo/string-calculator.git

Include the header file in your project:

    #include "string-calculator/StringCalculator.hpp"

## Usage
# Basic Calculation
To perform a basic calculation, initialize the StringCalculator object and call the calculate method with the mathematical expression as a string:
```
#include "string-calculator/StringCalculator.hpp"

int main() {
    StringCalculator sc;
    double result = sc.calculate("3 + (sqrt(4) * 12)");
    std::cout << "Result: " << result << std::endl; // Outputs: Result: 27
    return 0;
}
```
# Declaring Variables
You can declare variables that can be used in subsequent calculations:
```
#include "string-calculator/StringCalculator.hpp"

int main() {
    StringCalculator sc;
    sc.declare_variable("X=6");
    double result = sc.calculate("X + 12");
    std::cout << "Result: " << result << std::endl; // Outputs: Result: 18
    return 0;
}
```
# Custom Functions

The library allows you to define custom mathematical functions by modifying the functions.hpp file. To add a new function, follow these steps:

- Open functions.hpp: Locate the functions.hpp file in the string-calculator directory.

- Define your function: Add your custom function implementation.
```
    inline const static std::unordered_map<std::string, std::function<double(std::shared_ptr<Expression>)>> function_map =
    {
        [put your function here] !
        {"sin", [](std::shared_ptr<Expression> ex) { return std::sin(ex->result()); }},
        {"cos", [](std::shared_ptr<Expression> ex) { return std::cos(ex->result()); }},
        {"sqrt", [](std::shared_ptr<Expression> ex) { return std::sqrt(ex->result()); }}
    };
```
# Run tests

to run test use following commands

    make build_test
    make run_test

