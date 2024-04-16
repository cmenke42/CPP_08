#include <iostream>
#include <vector>
#include <string>

#include "easyfind.hpp"
#include "colors.h"

#define NOT_FOUND RED "not found" RESET

int main(void)
{
	std::cout << YELLOW << "------- Testing with: std::vector<int> -------" << RESET << std::endl;
	std::vector<int> intVector;
	for (int i = 0; i < 10; i++)
	{
		intVector.push_back(i);
	}
	std::cout << BLUE << "Contents of intVector: " << RESET << GREEN << std::endl;
	for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
	
	std::vector<int>::iterator intVectorIt;
	std::cout << BLUE << "Searching for -1 in intVector: " << RESET << std::endl;
	intVectorIt = easyFind(intVector, -1);
	if (intVectorIt != intVector.end())
		std::cout << *intVectorIt << std::endl;
	else
		std::cout << NOT_FOUND << std::endl;

	std::cout << BLUE << "Searching for 5 in intVector: " << RESET << std::endl;
	intVectorIt = easyFind(intVector, 5);
	if (intVectorIt != intVector.end())
		std::cout << *intVectorIt << std::endl;
	else
		std::cout << NOT_FOUND << std::endl;
	std::cout << std::endl;


	std::cout << YELLOW << "------- Testing with: std::string -------" << RESET << std::endl;
	std::string str = "Hello";
	std::cout << BLUE << "Contents of str: " << RESET << GREEN << str << RESET << std::endl;
	std::cout << BLUE << "Searching for 'e' in str: " << RESET << std::endl;
	std::string::iterator strIt;
	strIt = easyFind(str, 'e');
	if (strIt != str.end())
		std::cout << *strIt << std::endl;
	else
		std::cout << NOT_FOUND << std::endl;

	std::cout << BLUE << "Searching for 'z' in str: " << RESET << std::endl;
	strIt = easyFind(str, 'z');
	if (strIt != str.end())
		std::cout << *strIt << std::endl;
	else
		std::cout << NOT_FOUND << std::endl;
	std::cout << std::endl;


	std::cout << YELLOW << "------- Testing with: empty std::vector<int> -------" << RESET << std::endl;
	std::vector<int> emptyVector;
	emptyVector.resize(0);
	std::cout << BLUE << "Contents of emptyVector: " << RESET << GREEN << std::endl;
	for (std::vector<int>::iterator it = emptyVector.begin(); it != emptyVector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << BLUE << "Searching for 5 in emptyVector: " << RESET << std::endl;
	std::vector<int>::iterator emptyVectorIt;
	emptyVectorIt = easyFind(emptyVector, 5);
	if (emptyVectorIt != emptyVector.end())
		std::cout << *emptyVectorIt << std::endl;
	else
		std::cout << NOT_FOUND << std::endl;
	std::cout << std::endl;

	return 0;
}
