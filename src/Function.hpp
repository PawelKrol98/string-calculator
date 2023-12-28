#include "Expression.hpp"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>

class Function : public Expression
{
private:
    static std::unordered_map<std::string, std::function<double(Expression*)>> function_map;
    std::string function_name;
    Expression* argument;
public:
    static std::unordered_set<std::string> get_function_names();
    Function();
    double result() override;
};
