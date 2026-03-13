
#include <iostream>
#include <list>
#include "MutantStack.hpp"

void testMutantStack()
{
	std::cout << "============== MutantStack Test ==============" << std::endl;

	MutantStack<int> mstack;

	std::cout << "Pushing: 5, 17" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	std::cout << "Pop top element" << std::endl;
	mstack.pop();

	std::cout << "Current size: " << mstack.size() << std::endl;

	std::cout << "Pushing: 3, 5, 737, 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	for (; it != ite; ++it)
		std::cout << "  value = " << *it << std::endl;
}
// Shows that your MutantStack still behaves like a normal stack:
// push() adds elements to the top
// top() shows the top element
// pop() removes the top element


void testList()//Confirms that MutantStack mimics a normal container when iterated.
{
	std::cout << "\n============== std::list Test =============" << std::endl;

	std::list<int> lst;

	std::cout << "Pushing back: 5, 17" << std::endl;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Pop back element" << std::endl;
	lst.pop_back();

	std::cout << "Current size: " << lst.size() << std::endl;

	std::cout << "Pushing back: 3, 5, 737, 0" << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iterating list:" << std::endl;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	for (; it != ite; ++it)
		std::cout << "  value = " << *it << std::endl;
}

int main()
{
	testMutantStack();
	testList();
	return 0;
}
