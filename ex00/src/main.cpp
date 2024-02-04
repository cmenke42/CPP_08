#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> intVector;
	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);

	std::vector<int>::iterator it;
	it = easyFind(intVector, -1);
	if (it != intVector.end())
		std::cout << *it << std::endl;
	else
		std::cout << "not found" << std::endl;


	std::string str = "Hello";
	std::string::iterator itStr;
	itStr = easyFind(str, 'e');
	if (itStr != str.end())
		std::cout << (char)*itStr << std::endl;
	else
		std::cout << "str not found" << std::endl;
	
	// std::map<int, int> myMap;
	// myMap[0] = 3;
	// std::map<int, int>::iterator itMap;
	// itMap = easyFind(myMap, 2);
	// if (itMap != myMap.end())
	// 	std::cout << itMap->first << std::endl;
	// else 
	// 	std::cout << "map not found" << std::endl;
	return 0;
}
