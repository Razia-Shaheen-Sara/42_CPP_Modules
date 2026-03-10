
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Data.hpp"

class Serializer
{
private:
	Serializer() = delete;
	~Serializer() = delete;
	Serializer(const Serializer &src) = delete;
	Serializer &operator=(const Serializer &src) = delete;
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif
