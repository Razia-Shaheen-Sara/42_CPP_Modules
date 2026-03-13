#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 5

static void printSeparator()
{
    std::cout << "\n----------------------------------------\n" << std::endl;
}

static void testDefaultInitialization()
{
    printSeparator();
    std::cout << "TEST 0: Default initialization of new array elements\n" << std::endl;

    Array<int> defaultArray(3); // Using parameterized constructor
    for (unsigned int i = 0; i < defaultArray.size(); i++)
    {
        std::cout << "defaultArray[" << i << "] = " << defaultArray[i] << std::endl;
    }
}

static void fillArrays(Array<int>& arr, int* mirror)
{
    printSeparator();
    std::cout << "TEST 1: Filling arrays with random values\n" << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        int value = rand();
        arr[i] = value;
        mirror[i] = value;

        std::cout << "Index " << i << " -> value = " << value << std::endl;
    }
}

static void printArrays(Array<int>& arr, const int* mirror)
{
    printSeparator();
    std::cout << "TEST 2: Verifying operator[] correctly stores and retrieves values\n" << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Index " << i 
                  << " | mirror (C array) = " << mirror[i]
                  << " | Array (template) = " << arr[i]
				  << std::endl;

    }
}

static void testCopyConstructor(Array<int>& original)
{
    printSeparator();
    std::cout << "TEST 3: Copy constructor (deep copy test)\n" << std::endl;

    Array<int> copy(original);
    std::cout << "Original[0] before change = " << original[0] << std::endl;
    copy[0] = 42;
    std::cout << "Copy[0] changed to 42\n";
    std::cout << "Original[0] after change = " << original[0] << std::endl;

}

static void testCopyAssignment(Array<int>& source)
{
    printSeparator();
    std::cout << "TEST 4: Copy assignment operator (deep copy test)\n" << std::endl;

    Array<int> assigned;
    assigned = source;

    std::cout << "Source[1] before change = " << source[1] << std::endl;
    assigned[1] = 99;
    std::cout << "Assigned[1] changed to 99\n";
    std::cout << "Source[1] after change = " << source[1] << std::endl;

}

static void testSize(Array<int>& arr)
{
    printSeparator();
    std::cout << "TEST 5: size() function\n" << std::endl;

    std::cout << "Array size = " << arr.size() << std::endl;
}

static void testEmptyArray()
{
    printSeparator();
    std::cout << "TEST 6: Default constructor (empty array)\n" << std::endl;

    Array<int> empty;

    std::cout << "Empty array size = " << empty.size() << std::endl;
}

static void testOutOfBounds(Array<int>& arr)
{
    printSeparator();
    std::cout << "TEST 7: Out-of-bounds access (exception test)\n" << std::endl;

    try
    {
        std::cout << "Accessing index -1\n";
        arr[-1] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Accessing index MAX_VAL\n";
        arr[MAX_VAL] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
     std::cout << "TEST X: Subject tip - new int() vs new int\n";

    int *a = new int();   // with ()
    int *b = new int;     // without ()

    std::cout << "*a (value-initialized) = " << *a << std::endl;
    std::cout << "*b (default-initialized) = " << *b << " (may be garbage)" << std::endl;

    delete a;
    delete b;
    
    
    srand(time(NULL));

    printSeparator();
    std::cout << "ARRAY TEMPLATE TEST PROGRAM\n" << std::endl;
    testDefaultInitialization();

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    fillArrays(numbers, mirror);
    printArrays(numbers, mirror);

    testCopyConstructor(numbers);
    testCopyAssignment(numbers);
    testSize(numbers);
    testEmptyArray();
    testOutOfBounds(numbers);

    printSeparator();
    std::cout << "All tests finished.\n" << std::endl;

    delete [] mirror;
    return 0;
}



//What is the point of this exercise?
//
// 1.class templates- template <typename T> the same container works for int, string, etc.
// 2. Dynamic memory management- Use new[] / delete[].
// 3. Rule of Three-Copy constructor-Copy assignment operator-Destructor- Needed because you manage heap memory.
// 4. Deep copy- Copying an array must create new memory, not share it.
// 5. Operator overloading
// 6. Implement operator[].
// 7. Exception handling
// 8. Throw std::exception if index is out of bounds.
// Basically: you build a simplified version of std::vector / std::array behavior.