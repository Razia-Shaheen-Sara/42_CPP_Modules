
#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>

void iter(T *array, const size_t length, void (*f)(T &))
{
	if (f)
	{
		for (size_t i = 0; i < length; i++)
			f(array[i]);
	}
}

#endif 