#pragma once

#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, unsigned int findMe)
{
	typename T::iterator it = std::find(container.begin(), container.end(), findMe);
	if (it == container.end())
		throw std::out_of_range ("Element not found!");
	return it;
}