#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T& myCont, int value)
{
    for (typename T::iterator it = myCont.begin(); it != myCont.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    return myCont.end(); 
}

#endif

//In C++ Standard Template Library (STL) containers, 
//when functions(like std::find)fails to find a specified value or key, 
//it returns an iterator pointing to the end of the container


//Subject: Write a function template easyfind that "accepts a type T".
//“accepts a type T” → the template can work with any type


//template is a keyword in C++.
//It tells the compiler you are defining a generic function or class.

//typename: also a C++ keyword.
//It declares a type placeholder.

//T is the name of that placeholder, could be XYZ or mytype or whatever

//Container 
//a class that stores many elements.
//Example:
//std::vector → dynamic array
//std::list → linked list
//std::deque → double ended queue
//ALL standard containers come with their own iterators, .begin, .end


//Iterator:
//An iterator is a pointer like thing that points to an element inside a container. like a
//bookmark in a book but attached to the book since containers have their own iterators

//T::iterator meaning -- this function returns an iterator from T


//How everything is connected?
//every container comes with it's own iterator and functions
//Template function (like easyfind here) only says how it will work theoritically
//Now when we pass data from main, compiler will check if we have passed a container
//does it have iterator, and related functions
