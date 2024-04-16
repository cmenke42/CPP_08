#include "Span.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <vector>

#include "colors.h"

/* -------------------------- class Span -------------------------- */

Span::Span(unsigned int N)
	  : _maxSize(N)
{
	this->_array.reserve(N);
}

Span::Span(const Span& other)
		: _array(other._array),
			_maxSize(other._maxSize)
{
}

Span& Span::operator=(Span other)
{
	this->_array = other._array;
	this->_maxSize = other._maxSize;
	return (*this);
}

Span::~Span()
{
}

void Span::swap(Span& other)
{
	std::swap(this->_array, other._array);
	std::swap(this->_maxSize, other._maxSize);
}

/**
 * @throws std::runtime_error -> If Span can't accommodate the number
 */
void Span::addNumber(int number)
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

void Span::print(std::string name) const
{
	std::cout << CYAN << "Contents of " << name << " -->" << GREEN << std::endl;
	std::for_each(this->_array.begin(),
	              this->_array.end(),
				        Span::_printValue);
	std::cout << CYAN << "\n<--End of " << name << " contents." << RESET << std::endl;
}

void Span::printFirstTenElements(std::string name) const
{
	std::cout << CYAN << "First ten elements of " << name << " -->" << GREEN << std::endl;
	for (unsigned int i = 0; i < 10 && i < this->_array.size(); i++)
	{
		_printValue(this->_array[i]);
	}
	std::cout << GREEN << "... " << RESET;
	std::cout << CYAN << "\n<--End of " << name << " first ten elements." << RESET << std::endl;
}

void Span::_printValue(const int& value)
{
  std::cout << value << " ";
}

/* -------------------------- non-member functions -------------------------- */

template <typename T>
void swap(Span& left, Span& right)
{
	left.swap(right);
}
