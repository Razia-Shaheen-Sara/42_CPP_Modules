#include "Serializer.hpp"

//SERIALIZATION AND DESERIALIZATION
//serialization is converting a data structure or object
//into a format that can be easily stored or transmitted and then reconstructed later.
//example: converting a pointer to an integer type that can safely hold its value without loss of information.
//converting serialized data back into its original form is called deserialization.

//UNINTPTR_T
//It is an "unsigned integer type" that is guaranteed to be able to hold a pointer.
//from <cstdint> header and is used for serialization deserialization of pointers

//REINTERPRET_CAST
//It is a C++ type conversion operator
//converts a pointer of one type to a pointer of another type, even if the types are unrelated.

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}