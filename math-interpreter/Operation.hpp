#pragma once
#include "Expression.hpp"

class Operation : public Expression
{
private:
    char operand;
    Expression* argument1;
    Expression* argument2;

public:
    Operation(char _operand, Expression* _argument1, Expression* _argument2) : 
                                                                        operand(_operand),
                                                                        argument1(_argument1),
                                                                        argument2(_argument2)
    {
    }

    ~Operation ()
    {
        delete argument1;
        delete argument2;
    }

    double result() override
    {
		std::cout << "DEBUG executing operation operand" << std::endl;
        if (operand == '+')
        {
            return argument1->result() + argument2->result();
        }
        else if (operand == '-')
        {
            return argument1->result() - argument2->result();
        }
        else if (operand == '*')
        {
            return argument1->result() * argument2->result();
        }
        else if (operand == '/')
        {
            return argument1->result() / argument2->result();
        }
		std::cout << "WARNING operand argument is incorrect" << std::endl; 
		return 0;
    }
};
