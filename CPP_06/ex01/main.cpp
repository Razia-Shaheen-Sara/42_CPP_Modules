#include "Serializer.hpp"

int main()
{
	Data* myData = new Data();
	myData->name = "XYZ";
	myData->age = 60;

	std::cout << "Original Data address: " << myData << std::endl;

	uintptr_t serializedValue = Serializer::serialize(myData);
	std::cout << "Serialized value: " << serializedValue << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedValue);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;

	if (deserializedData == myData)
	{
		std::cout << "Success: The pointers are equal." << std::endl;
		std::cout << "Data content: name='" << deserializedData->name << "', age=" << deserializedData->age << std::endl;
	}
	else
	{
		std::cout << "Failure: The pointers are not equal." << std::endl;
	}
	delete myData;

	return 0;
}