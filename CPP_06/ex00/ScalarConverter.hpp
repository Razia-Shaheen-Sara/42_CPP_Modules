#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter() = delete;//if not explicitly written and deleted, compiler may automatically produce it
	    ~ScalarConverter() = delete;
	    ScalarConverter(const ScalarConverter &src) = delete;
	    ScalarConverter &operator=(const ScalarConverter &src) = delete;
    public:
	    static void	convert(const std::string &input);//static = belongs to the class, not to objects
};


//How to make a class "NOT INSTANTIABLE(cannot make objects from it)":
//Make constructor and destructor private. 
//optional: Delete constructor, destructor, copy, assignment


//subject:  class doesn’t need to store anything at all -- no member variables -- Everything works only from the input parameter
//this behavior is called namespace(a place for a name only) but made into a class. It is a dummy class, not meant to be instantiated.
// when a member function of a class is declared static, it means that the function
//belongs to the CLASS itself, and NOT to any specific instance of the class.
//-cannot access *THIS, and has no access to instance members


//int → whole numbers
//float → decimal numbers (less precise)- float  f = 4.2f;
//double → decimal numbers (more precise)- double d = 4.2;
//Pseudo-literals (special values of float/double)
//nan, +inf, -inf → double
//nanf, +inff, -inff → float
//nan → not a number
//inf → infinity
