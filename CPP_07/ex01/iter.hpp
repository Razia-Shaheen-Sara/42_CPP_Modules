
#ifndef ITER_H
#define ITER_H

#include <iostream>

//Requirement:
//It needs to work for both const and non const reference
//Solution:
//*Let the function pointer also be templated */ so it can accept both
//- void f(T&)
//- void f(const T&)
//The Goal: 
//iter must be able to handle a double, a std::string, or a Fixed class 
//without changing a single line of the iter function itself.

template <typename T, typename F>
void iter(T *array, const size_t length, F function)
{
	if (!array)
        return;
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif 