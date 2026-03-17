#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {} //default constructor
RPN::RPN(const RPN& source) : _stack(source._stack) {} //copy constructor
RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}


//std::istringstream is a stream that reads from a string instead of a file or the console.
//it splits the string by whitespace automatically.

int RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);//iss becomes a stream that reads from expression.
    std::string token;//token will hold each piece (3, 4, +, etc.)

    while (iss >> token)
    {
        
        if (token.length() == 1 && std::isdigit(token[0])) // (subject says numbers < 10)
        {
            _stack.push(token[0] - '0');  // convert char to int
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            
            if (_stack.size() < 2)// Need at least 2 numbers to calculate
                throw std::runtime_error("Error");

            int b = _stack.top(); _stack.pop();  // right operand
            int a = _stack.top(); _stack.pop();  // left operand

            if (token == "+") _stack.push(a + b);
            else if (token == "-") _stack.push(a - b);
            else if (token == "*") _stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                _stack.push(a / b);
            }
        }
        else
        {
            throw std::runtime_error("Error");  // invalid token
        }
    }
    // At the end, exactly 1 number should remain
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return _stack.top();
}


//Why std::stack? Because the algorithm is LIFO (Last In First Out) — the last numbers pushed
// are the first ones you use when you hit an operator.

