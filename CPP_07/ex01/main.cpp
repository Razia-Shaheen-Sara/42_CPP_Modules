#include "iter.hpp"

template <typename T>
void printArray(T &element)
{
	std::cout << element << " ";
}

template <typename T>
void addOne(T &element)
{
	element++;
}

int main()
{
	void (*fptr)(int &x) = nullptr;
	int const Carray[4] = {0, 1, 2, 3};
	int array[4] = {0, 1, 2, 3};
	char string[] = "abc";
	
	::iter(array, 4, fptr);
	
	::iter(Carray, 4, printArray);
	
	::iter(array, 4, addOne);
	::iter(array, 4, printArray);

	::iter(string, sizeof(string), printArray);
	::iter(string, sizeof(string), addOne);
	::iter(string, sizeof(string), printArray);

}