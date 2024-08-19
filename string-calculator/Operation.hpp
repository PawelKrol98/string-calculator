#pragma once
#include "Expression.hpp"
#include <memory>

class Operation : public Expression
{
private:
    char operand_;
    std::shared_ptr<Expression> argument1_;
    std::shared_ptr<Expression> argument2_;

public:
    Operation(char operand, std::shared_ptr<Expression> argument1, std::shared_ptr<Expression> argument2) : 
                                                                         operand_(operand),
                                                                         argument1_(argument1),
                                                                         argument2_(argument2)
    {
    }

    ~Operation () {}

    double result() override
    {
		//std::cout << "DEBUG executing operation operand" << operand_ << std::endl;
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
