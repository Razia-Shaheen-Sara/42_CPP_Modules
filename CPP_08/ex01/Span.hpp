#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int		_max_length;
	std::vector<int>	_numbers;

public:
	Span(unsigned int max_len);
	Span(const Span &src);
	Span operator=(const Span &src);
	~Span();

	template <typename IT>//needs to be a template to work with different cont. like vec, list etc
	void addNumber(IT begin, IT end)
	{
		if(_numbers.size() + std::distance(begin, end) > _max_length)
		{
			throw std::overflow_error("ERROR: span is full, you can not add anymore number!");
		}
		_numbers.insert(_numbers.end(), begin, end);
	}
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif

//from subject:  fill your Span using a range of iterators meaning
// numbers.begin() → numbers.end()
