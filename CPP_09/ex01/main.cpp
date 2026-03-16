#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    RPN rpn;
    try
    {
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}


// ./RPN "3 4 +" // 7
// ./RPN "5 1 2 + 4 * + 3 -" // 14
// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" // 42
// ./RPN "1 +" // Error
// ./RPN "1 2 3 +" // Stack ends with 2 numbers → invalid.
// ./RPN "4 0 /"// Error
// ./RPN "2 3 a +"// Error
// ./RPN "10 2 +"// Error
// ./RPN "-1 2 +"// Error Because subject allows only digits 0–9.
// ./RPN "+ 2 3"// Error
// ./RPN "" // Error
// ./RPN "  3   4    +   " // 7
// ./RPN "9 9 9 9 + + +"// 36. This checks if stack logic is correct.
//./RPN 3 4 +  //Error: usage: ./RPN "expression"
//./RPN "+" // Error
// ./RPN "1 2 3"
// ./RPN "9 8 7 6 5 4 3 2 1 + + + + + + + +"// 45
// ./RPN "0 0 +" // 0
//./RPN "3 4+" //Error coz no space
//./RPN "9 9 * 9 * 9 *" //6561
//./RPN "1 2 + +" //Error coz not enough operands for second +