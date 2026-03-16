#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN& source);
        RPN& operator=(const RPN& source);
        ~RPN();

        int evaluate(const std::string& expression);
};

#endif


//In RPN, the operator comes after the numbers: 3 4 +
//The operator always acts on the two numbers that came just before it.

//Execution Rule:
//See a number → push it onto the stack
//See an operator → pop the top 2 numbers, apply the operator, push the result back