#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <stdlib.h>

//destructor is virtual because we will be deleting objects of derived classes (A, B, C) through a pointer to the base class (Base*).

class Base
{
public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);


#endif