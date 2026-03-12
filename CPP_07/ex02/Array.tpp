
#include "Array.hpp"

//tip from subject:
// int *a = new int();
// std::cout << *a << std::endl;
// It Allocates one int on the heap.
// The () value---initializes it → for int, it becomes 0.
// Without (), int *a = new int; → uninitialized garbage.


template<typename T>
Array<T>::Array() : arr(nullptr), n_size(0){}//initializer list to set value before execution of {}


// arr = new T[n](); 
// The () value-initializes each element of type T in the array.
// For int -> 0, for std::string -> empty string, etc.
// Without (), primitive types like int would contain garbage values.
//but still okay for std::string

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), n_size(n){}

template<typename T>
Array<T>::Array(const Array &src)
{
	this->n_size = src.n_size;
	this->arr = new T[src.n_size];
	for(unsigned int i = 0; i < src.n_size; i++)
	{
		this->arr[i] = src.arr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if(this != &src)
	{
		delete [] this->arr;
		this->n_size = src.n_size;
		this->arr = new T[src.n_size];
		for(unsigned int i = 0; i < src.n_size; i++)
		{
			this->arr[i] = src.arr[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->arr;
}

template<typename T>
T &Array<T>::operator[](const unsigned int pos)
{
	if(pos >= this->n_size)
	{
		throw std::out_of_range("Error: Out of the array range");
	}
	return this->arr[pos];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->n_size);
}
