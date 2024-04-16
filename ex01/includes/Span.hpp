#ifndef SPAN_HPP_INCLUDED
#define SPAN_HPP_INCLUDED

#include <vector>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(Span other);
	~Span();

	void					swap(Span& other);

	void 					addNumber(int number);
	template <typename const_iterator>
	void 					addRange(const_iterator first, const_iterator last);

	unsigned int 	shortestSpan() const;
	unsigned int 	longestSpan() const;

	void 					print(std::string name) const;
	void 					printFirstTenElements(std::string name) const;


private:
	typedef std::vector<int>	_ArrayType;
	Span::_ArrayType 					_array;
	unsigned int 							_maxSize;

	static void _printValue(const int& value);
};

template <typename T>
void swap(Span& left, Span& right);

#include "../src/Span.tpp"

#endif /* SPAN_HPP_INCLUDED */