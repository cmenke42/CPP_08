#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <limits>

#include "Span.hpp"
#include "colors.h"

#define SHORT_SPAN PINK "Shortest Span:\t" RESET
#define LONG_SPAN PINK "Longest Span:\t" RESET
#define BIG_SPAN_MAX 100000

void testFromSubject();
void testAddRange();
void testAddRangeConst();
void testExceptions();
void testMixedAddingOfNumbers();
void testBigSpanWithRange(const std::vector<int>& vectorInt);
void testBigSpan(const std::vector<int>& vectorInt);
void testMaxValues();

int main()
{
	testFromSubject();
	testAddRange();
	testAddRangeConst();
	testExceptions();
	testMixedAddingOfNumbers();

	std::cout << YELLOW << "------- Preparing vector with random numbers -------" << RESET << std::endl;
	std::cout << BLUE << "Creating a vector with: 0 - " << BIG_SPAN_MAX - 1 << std::endl;
  std::vector<int> vectorInt(BIG_SPAN_MAX);
  for (int i = 0; i < BIG_SPAN_MAX; ++i)
	{
    vectorInt[i] = i;
  }
	std::cout << BLUE << "Shuffling the vector" << std::endl;
	std::srand(std::time(0));
  std::random_shuffle(vectorInt.begin(), vectorInt.end());
	testBigSpanWithRange(vectorInt);
	std::cout << BLUE << "Shuffling the vector" << std::endl;
	std::random_shuffle(vectorInt.begin(), vectorInt.end());
	testBigSpan(vectorInt);

	testMaxValues();
	return 0;
}

void testFromSubject()
{
	std::cout << YELLOW << "------- Tests from the Subject -------" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testAddRange()
{
	std::cout << YELLOW << "------- Test addRange() -------" << RESET << std::endl;
	const unsigned int maxSize = 10;
	Span sp = Span(maxSize);
	int numbers[maxSize] = {-1, 2, 3, 40, 5, 6, -900, 8, -9, 1000};
	sp.addRange(numbers, numbers + maxSize);
	sp.print("sp");
	std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testAddRangeConst()
{
	std::cout << YELLOW << "------- Test addRange() with const -------" << RESET << std::endl;
	const unsigned int maxSize = 100;
	std::cout << BLUE << "Creating a vector with " << maxSize << " elements" << std::endl;
	std::vector<int> vectorInt;
	for (unsigned int i = 0; i < maxSize; ++i)
	{
		vectorInt.push_back(i);
	}
	std::cout << "Contents of vectorInt: " << GREEN << std::endl;
	for (std::vector<int>::const_iterator it = vectorInt.begin(); it != vectorInt.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << BLUE << "Filling Span with vectorInt::const_iterator" << std::endl;
	Span sp = Span(maxSize);
	std::vector<int>::const_iterator vectorConstItBegin = vectorInt.begin();
	std::vector<int>::const_iterator vectorConstItEnd = vectorInt.end();
	sp.addRange(vectorConstItBegin, vectorConstItEnd);
	sp.print("sp");
	std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "------- Test assignment operator -------" << RESET << std::endl;
	Span sp2(maxSize);
	std::cout << BLUE << "sp2 = sp" << std::endl;
	sp2 = sp;
	sp2.print("sp2");
	std::cout << SHORT_SPAN << sp2.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp2.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testExceptions()
{
	std::cout << YELLOW << "------- Test exceptions -------" << RESET << std::endl;
	std::cout << BLUE << "Empty Span" << std::endl;
	Span sp = Span(0);
	try
	{
		std::cout << BLUE << "Trying to get the shortest span" << std::endl;
		std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << BLUE << "Trying to get the longest span" << std::endl;
		std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << BLUE << "Trying addNumber" << std::endl;
		sp.addNumber(42);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "Creating a Span with maxSize = 5" << std::endl;
	Span sp2 = Span(5);
	try
	{
		std::cout << BLUE << "Trying to add 6 numbers" << std::endl;
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		sp2.addNumber(4);
		sp2.addNumber(5);
		sp2.addNumber(6);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	sp2.print("sp2");
	try
	{
		std::cout << BLUE << "Trying to add a bigger range" << RESET << std::endl;
		int numbers[6] = {1, 2, 3, 4, 5, 6};
		sp2.addRange(numbers, numbers + 6);
	}	
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void testMixedAddingOfNumbers()
{
	std::cout << YELLOW << "------- Test mixed adding of numbers -------" << RESET << std::endl;
	std::cout << BLUE << "Creating a Span with maxSize = 10" << std::endl;
	const unsigned int maxSize = 10;
	Span sp = Span(maxSize);
	sp.addNumber(1);
	sp.print("sp");

	std::cout << BLUE << "Adding a range of 4 numbers" << std::endl;
	int numbers[4] = {2, 3, 4, 5};
	sp.addRange(numbers, numbers + 4);
	sp.print("sp");

	std::cout << BLUE << "Adding a range of 3 numbers" << std::endl;
	int numbers2[3] = {6, 7, 8};
	sp.addRange(numbers2, numbers2 + 3);
	sp.print("sp");

	std::cout << BLUE << "Adding one number" << std::endl;
	sp.addNumber(9);
	sp.print("sp");
	std::cout << BLUE << "Adding one number" << std::endl;
	sp.addNumber(10);
	sp.print("sp");

	std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testBigSpanWithRange(const std::vector<int>& vectorInt)
{
	std::cout << YELLOW << "------- Test big Span -------" << RESET << std::endl;
	std::cout << BLUE << "Creating a Span with maxSize = " << BIG_SPAN_MAX << std::endl;
	Span sp = Span(BIG_SPAN_MAX);
	std::cout << BLUE << "Adding a range of " << BIG_SPAN_MAX << " numbers" << std::endl;
	sp.addRange(vectorInt.begin(), vectorInt.end());
	sp.printFirstTenElements("sp");
	// sp.print("sp");
	std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testBigSpan(const std::vector<int>& vectorInt)
{
	std::cout << YELLOW << "------- Test big Span -------" << RESET << std::endl;
	std::cout << BLUE << "Creating a Span with maxSize = " << BIG_SPAN_MAX << std::endl;
	Span sp = Span(BIG_SPAN_MAX);
	std::cout << BLUE << "Adding " << BIG_SPAN_MAX << " numbers" << std::endl;
	for (unsigned int i = 0; i < BIG_SPAN_MAX; ++i)
	{
		sp.addNumber(vectorInt[i]);
	}
	sp.printFirstTenElements("sp");
	// sp.print("sp");
	std::cout << SHORT_SPAN << sp.shortestSpan() << std::endl;
	std::cout << LONG_SPAN << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testMaxValues()
{
	std::cout << YELLOW << "------- Test max values -------" << RESET << std::endl;
	std::cout << BLUE << "Filling span with IntMIN and IntMAX" << RESET << std::endl;
	Span sp = Span(2);
	sp.addNumber(std::numeric_limits<int>::min());
	sp.addNumber(std::numeric_limits<int>::max());
	sp.print("sp");

	long int reference = static_cast<long int>(std::numeric_limits<int>::min()) - static_cast<long int>(std::numeric_limits<int>::max());
	reference = std::abs(reference);
	unsigned int minSpan = sp.shortestSpan();
	unsigned int maxSpan = sp.longestSpan();
	std::cout << BLUE << "Values: " << RESET << std::endl;
	std::cout << "Reference:\t " << reference << std::endl;
	std::cout << "Shortest Span:\t " << minSpan << std::endl;
	std::cout << "Longest Span:\t " << maxSpan << std::endl;
	if (minSpan == reference && maxSpan == reference)
		std::cout << GREEN << "Values match reference" << RESET << std::endl;
	else
		std::cout << RED << "Values do not match reference" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Filling span with IntMAX and IntMAX" << RESET << std::endl;
	Span sp2 = Span(2);
	sp2.addNumber(std::numeric_limits<int>::max());
	sp2.addNumber(std::numeric_limits<int>::max());
	sp2.print("sp2");
	reference = 0;
	minSpan = sp2.shortestSpan();
	maxSpan = sp2.longestSpan();
	std::cout << BLUE << "Values: " << RESET << std::endl;
	std::cout << "Reference:\t " << reference << std::endl;
	std::cout << "Shortest Span:\t " << minSpan << std::endl;
	std::cout << "Longest Span:\t " << maxSpan << std::endl;
	if (minSpan == reference && maxSpan == reference)
		std::cout << GREEN << "Values match reference" << RESET << std::endl;
	else
		std::cout << RED << "Values do not match reference" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Filling span with IntMIN and IntMIN" << RESET << std::endl;
	Span sp3 = Span(2);
	sp3.addNumber(std::numeric_limits<int>::min());
	sp3.addNumber(std::numeric_limits<int>::min());
	sp3.print("sp3");
	reference = 0;
	minSpan = sp3.shortestSpan();
	maxSpan = sp3.longestSpan();
	std::cout << BLUE << "Values: " << RESET << std::endl;
	std::cout << "Reference:\t " << reference << std::endl;
	std::cout << "Shortest Span:\t " << minSpan << std::endl;
	std::cout << "Longest Span:\t " << maxSpan << std::endl;
	if (minSpan == reference && maxSpan == reference)
		std::cout << GREEN << "Values match reference" << RESET << std::endl;
	else
		std::cout << RED << "Values do not match reference" << RESET << std::endl;
	std::cout << std::endl;
}
