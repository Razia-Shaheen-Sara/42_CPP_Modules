#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(){}

//rand() → generates a pseudo-random number.
//srand() → sets the seed (starting point) for rand()
//without srand, rand() will produce the same sequence of numbers each time the program runs. 
//rand() % 3 == Take the random number from rand() and get the remainder when divided by 3.
//% 3 because we have 3 possible choices A, B or C. It will give us a number between 0 and 2, 
//which we can use to randomly select one of the three classes.


Base * generate(void)
{

	int random = (std::rand() % 3);
	switch (random)
	{
	case 0:
		std::cout << "Class A created." << std::endl;
		return new A;
	case 1:
		std::cout << "Class B created." << std::endl;
		return new B;
	case 2:
		std::cout << "Class C created." << std::endl;
		return new C;
	default:
		std::cout << "No class created." << std::endl;
		return nullptr;
	}
}

// DYNAMIC CAST (safe runtime type checking and casting)
// A C++ operator used for safely converting pointers and references
// along the inheritance hierarchy: upcasting, downcasting, and cross-casting.
//
// Upcasting:   derived → base   (always safe, rarely needs dynamic_cast)
// Downcasting: base → derived   (checked at runtime)
// Cross-cast:  between sibling classes in the hierarchy
//
// Requires RTTI (Runtime Type Information) to verify the conversion is valid at runtime.
// The SOURCE must be a pointer or reference to a POLYMORPHIC class
// (a class with at least one virtual function, typically a virtual destructor).
// The TARGET must be a pointer or reference to a class type.
// Note: both source and target must be related by inheritance — dynamic_cast
// cannot convert between unrelated class types.
//
// Pointer cast vs Reference cast:
// - Pointer:   if cast fails → returns nullptr
// - Reference: if cast fails → throws std::bad_cast exception
// <EndResultType*> = The type you want to convert TO.
// (source_pointer) = The pointer/reference you are converting FROM.

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) std::cout << "It is Class -A-\n";
	else if (dynamic_cast<B*>(p)) std::cout << "It is Class -B-\n";
	else if (dynamic_cast<C*>(p)) std::cout << "It is Class -C-\n";
	else std::cout << "It is -Unknown-\n";
}

//BAD_CAST
//std::bad_cast is an exception type in C++ that is thrown when a dynamic_cast fails to convert a pointer or reference to the desired type.

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It is Class --A--\n";
		return;
	}
	catch(std::bad_cast& e)
    {
		std::cout << "not Class A\n";
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "It is Class --B--\n";
		return;
	}
	catch(std::bad_cast& e)
    {
		std::cout << "not Class B\n";
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "It is Class --C--\n";
		return;
	}
	catch(std::bad_cast& e)
    {
		std::cout << "not Class C\n";
	}
	std::cout << "--Unknown--\n";
}