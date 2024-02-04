#include "Span.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <vector>

Span::Span(unsigned int N)
	 : _maxSize(N)
{
	this->_array.reserve(N);
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	this->_array = other._array;
	this->_maxSize = other._maxSize;
	return (*this);
}

Span::~Span()
{
}

/**
 * @throws std::runtime_error -> If Span can't accommodate the number
 */
void Span::addNumber(unsigned int number)
{
	if (this->_array.size() >= this->_maxSize)
		throw std::runtime_error("Span is already full. Can't add more");
	this->_array.push_back(number);
}

/**
 * @throws std::runtime_error -> If the current Span size < 2>.
 */
unsigned int Span::shortestSpan() const
{
    if (this->_array.size() < 2)
		throw std::runtime_error("No span to be found. Size < 2");

	Span::_ArrayType sortedArray(this->_array);
	std::sort(sortedArray.begin(), sortedArray.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	Span::_ArrayType::const_iterator sortedArrayEnd  = sortedArray.end() - 1;
	Span::_ArrayType::const_iterator sortedArrayIter = sortedArray.begin();
    for (; sortedArrayIter < sortedArrayEnd ; ++sortedArrayIter)
    {
        unsigned int currentSpan = *(sortedArrayIter + 1) - *sortedArrayIter;
        minSpan = std::min(minSpan, currentSpan);
        if (minSpan == 0)
            return (minSpan);
    }

    return (minSpan);
}

/**
 * @throws std::runtime_error -> If the current Span size < 2>.
 */
unsigned int Span::longestSpan() const
{
	 if (this->_array.size() < 2)
		throw std::runtime_error("No span to be found. Size < 2");
	
	unsigned int min;
	unsigned int max;

	min = *std::min_element(this->_array.begin(), this->_array.end());
	max = *std::max_element(this->_array.begin(), this->_array.end());

	return (max - min);
}

void Span::print() const
{
	std::cout << "Contents of Span:" << std::endl;
	std::for_each(this->_array.begin(),
	              this->_array.end(),
				  Span::_printValue);
	std::cout << "\nEnd of Contents" << std::endl;
}

void Span::_printValue(const unsigned int& value)
{
    std::cout << value << " ";
}
