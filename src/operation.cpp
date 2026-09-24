#include "string_calculator/operation.hpp"

double Operation::result() {
    //std::cout << "DEBUG executing operation operand" << operand_ << std::endl;
    if (operand_ == '+') {
        return argument1_->result() + argument2_->result();
    }
    else if (operand_ == '-') {
        return argument1_->result() - argument2_->result();
    }
    else if (operand_ == '*') {
        return argument1_->result() * argument2_->result();
    }
    else if (operand_ == '/') {
        return argument1_->result() / argument2_->result();
    }
    std::cout << "WARNING operand argument is incorrect" << std::endl; 
    return 0;
}
