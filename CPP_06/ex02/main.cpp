#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>
#include <exception>

//rand() → generates a pseudo-random number.
//srand() → sets the seed (starting point) for rand().


//point of this exercise:
//run time type identification using dynamic_cast 
//process: determine the actual type of an object when you only have a pointer or reference to its base class.
//
//Other Concepts:
//Polymorphism - getting different derived classes through a common base class
//
//Point of test:
//when the object type does not match(example, trying to cast a B object to A), 
//it will fail casting
//so dynamic_cast is trying to match object type.(example, A can cast to A, but not to B or C)

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\n===== TEST 1: identify() functions =====\n";
    for (int i = 0; i < 3; i++)
    {
        Base *p = generate();

        std::cout << "identify(pointer): ";
        identify(p);

        std::cout << "identify(reference): ";
        identify(*p);

        delete p;
        std::cout << std::endl;
    }


    std::cout << "\n===== TEST 2: dynamic_cast with POINTER =====\n";
    Base* p = generate();

    if (dynamic_cast<A*>(p))
        std::cout << "Cast to A succeeded\n";
    else
        std::cout << "Cast to A returned NULL\n";

    if (dynamic_cast<B*>(p))
        std::cout << "Cast to B succeeded\n";
    else
        std::cout << "Cast to B returned NULL\n";

    if (dynamic_cast<C*>(p))
        std::cout << "Cast to C succeeded\n";
    else
        std::cout << "Cast to C returned NULL\n";

    delete p;


    std::cout << "\n===== TEST 3: dynamic_cast with REFERENCE =====\n";
    Base* r = generate();

    try 
    {
        A& a = dynamic_cast<A&>(*r);
        (void)a;
        std::cout << "Cast to A succeeded\n";
    }
    catch (std::bad_cast& e) 
    {
        std::cout << "Cast to A threw exception\n";
    }
    try 
    {
        B& b = dynamic_cast<B&>(*r);
        (void)b;
        std::cout << "Cast to B succeeded\n";
    }
    catch (std::bad_cast& e) 
    {
        std::cout << "Cast to B threw exception\n";
    }

    try {
        C& c = dynamic_cast<C&>(*r);
        (void)c;
        std::cout << "Cast to C succeeded\n";
    }
    catch (std::bad_cast& e) 
    {
        std::cout << "Cast to C threw exception\n";
    }

    delete r;

    return 0;
}
