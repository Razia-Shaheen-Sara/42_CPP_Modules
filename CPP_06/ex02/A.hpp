#ifndef A_HPP
#define A_HPP
#include "Base.hpp"

//this public is for the inheritance, not for the members of A.
//it means that the public members of Base will be public in A, and protected members of Base will be protected in A.

class A : public Base {};

#endif