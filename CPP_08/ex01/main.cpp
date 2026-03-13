#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{

	std::cout << "\n----  Subject's Test----" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----  Error Test----" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(6);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n---- The -10000- Test ----" << std::endl;

	try
	{
		Span big(10000);
		std::vector<int> nums;

		for (int i = 0; i < 10000; i++)
			nums.push_back(i * 2);

		big.addNumber(nums.begin(), nums.end());

		std::cout << "Shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Longest: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}