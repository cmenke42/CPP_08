#include <iostream>
// #include <vector>
// #include <string>

#include <Span.hpp>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "short span: " << sp.shortestSpan() << std::endl;
	std::cout << "long span: " << sp.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	//copy cosntructor
	std::cout << "Span sp2 = sp" << std::endl;
	Span sp2 = sp;
	std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	std::cout << "long span: " << sp2.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	unsigned int maxSize = 10;
	sp2 = Span(maxSize + 1);
	unsigned int* numbers = new unsigned int[maxSize];
	for (unsigned int i = 0; i < maxSize; ++i)
	{
		numbers[maxSize - 1 - i] = i;
	}
	sp2.addNumber(numbers, numbers + maxSize); //works because you don't dereference the end
	sp2.addNumber(maxSize);
	sp2.print();
	std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	std::cout << "long span: " << sp2.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] numbers;
	numbers = NULL;

	maxSize = 10;
	sp2 = Span(maxSize + 2);
	numbers = new unsigned int[maxSize];
	for (unsigned int i = 0; i < maxSize; ++i)
	{
		numbers[maxSize - 1 - i] = i;
	}
	sp2.addNumber(numbers, numbers + maxSize);
	sp2.addNumber(546546);
	sp2.addNumber(maxSize - 1);
	sp2.print();
	std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	std::cout << "long span: " << sp2.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] numbers;
	numbers = NULL;

	//assignment operator
	std::cout << "sp2 = sp" << std::endl;
	sp2 = sp;
	std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	std::cout << "long span: " << sp2.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;


	maxSize = 1000000;
	sp2 = Span(maxSize + 1);
	numbers = new unsigned int[maxSize];
	for (unsigned int i = 0; i < maxSize; ++i)
	{
		numbers[maxSize - 1 - i] = i;
	}
	sp2.addNumber(numbers, numbers + maxSize);
	sp2.addNumber(maxSize);
	std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	std::cout << "long span: " << sp2.longestSpan() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	delete[] numbers;
	numbers = NULL;

	////compilation error
	// std::vector<std::string> test;
	// test.push_back("sdfkgklsdfjgksdfjg");
	// sp2 = Span(2);
	// sp2.addNumber(test.begin(), test.end());
	// std::cout << "short span: "<< sp2.shortestSpan() << std::endl;
	// std::cout << "long span: " << sp2.longestSpan() << std::endl;
	// std::cout << "-----------------------------" << std::endl;
	return 0;
}
