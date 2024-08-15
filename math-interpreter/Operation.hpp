#pragma once
#include "Expression.hpp"

class Operation : public Expression
{
private:
    char operand_;
    Expression* argument1_;
    Expression* argument2_;

public:
    Operation(char operand, Expression* argument1, Expression* argument2) : 
                                                                         operand_(operand),
                                                                         argument1_(argument1),
                                                                         argument2_(argument2)
    {
    }

    ~Operation ()
    {
        delete argument1_;
        delete argument2_;
    }

    double result() override
    {
		std::cout << "DEBUG executing operation operand" << operand_ << std::endl;
        if (operand_ == '+')
        {
            return argument1_->result() + argument2_->result();
        }
        else if (operand_ == '-')
        {
            return argument1_->result() - argument2_->result();
        }
        else if (operand_ == '*')
        {
            return argument1_->result() * argument2_->result();
        }
        else if (operand_ == '/')
        {
            return argument1_->result() / argument2_->result();
        }
		std::cout << "WARNING operand argument is incorrect" << std::endl; 
		return 0;
    }
};
