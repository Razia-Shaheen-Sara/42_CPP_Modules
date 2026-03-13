#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

#endif


//std::stack has a hidden container
// std::stack is not a “real” container like vector or list.
// Internally, it stores the elements in another container, usually a deque by default.
// This internal container is called c inside the std::stack implementation.
// You don’t see c directly in your code, but it exists because std::stack is basically a wrapper around a container.


// How this works
// Even though std::stack itself doesn’t provide begin() or end(), its internal container c does, so we can “borrow” them.
// this->c is a protected member of std::stack, which is why you can access it from a class that inherits std::stack.