#ifndef WHATEVER_H
#define WHATEVER_H

//template is a keyword in C++.
//It tells the compiler you are defining a generic function or class.


//typename: also a C++ keyword.
//It declares a type placeholder.

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const& min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T const& max(T const &a, T const &b)
{
	if (a < b)
		return b;
	return a;
}

#endif


//Templates is a way to--
//write one generic logic/function that works for many types
//example: swap, min and max here will work for int, float, double EVEN STR and CHAR--everything!
//The code has to be in header to be used as template

//RULE of whether it will work or not:
//A template works for a specific type, if the type supports the operations used inside the template.
//here operators = < > are used so any type that allows these operators can use this template

//char will compare ASCII values and str will compare lexicographic values
