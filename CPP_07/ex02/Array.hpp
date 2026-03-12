#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array

{
private:
	T* arr;
	unsigned int n_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array &operator=(const Array &src);
	~Array();

	T &operator[](const unsigned int pos);
	unsigned int size() const;
};

#endif