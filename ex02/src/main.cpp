#include <iostream>
#include <stack>
#include <list>

#include "MutantStack.hpp"
#include "colors.h"

void	testFromSubject();
void  testAlternativeSequence();
void  testCopyAndAssignSimple();
void	testCopyAndAssignComplex();

int main()
{
	testFromSubject();
	testAlternativeSequence();
	testCopyAndAssignSimple();
	testCopyAndAssignComplex();
	return 0;
}

void	testFromSubject()
{
	std::cout << YELLOW << "------- Test from subject -------" << RESET << std::endl;
	std::cout << BLUE << "MutantStack<int> mstack;" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " ";
	mstack.pop();
	std::cout << mstack.size() << " ";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << BLUE << "std::list<int> listReference;" << RESET << std::endl;
	std::list<int> listReference;
	listReference.push_back(5);
	listReference.push_back(17);
	std::cout << listReference.back() << " ";
	listReference.erase(--listReference.end());
	std::cout << listReference.size() << " ";
	listReference.push_back(3);
	listReference.push_back(5);
	listReference.push_back(737);
	//[...]
	listReference.push_back(0);
	std::list<int>::iterator listReferenceIt = listReference.begin();
	std::list<int>::iterator listReferenceIte = listReference.end();
	++listReferenceIt;
	--listReferenceIt;
	while (listReferenceIt != listReferenceIte)
	{
	std::cout << *listReferenceIt << " ";
	++listReferenceIt;
	}
	std::cout << std::endl;
	std::list<int> s2(listReference);
}

void testAlternativeSequence()
{
	std::cout << YELLOW << "------- Test with alternative sequence -------" << RESET << std::endl;
	std::cout << BLUE << "MutantStack<int, std::list<int> >" << RESET << std::endl;
	typedef MutantStack<int, std::list<int> > MstackType;
	MstackType mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " ";
	mstack.pop();
	std::cout << mstack.size() << " ";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MstackType::iterator it = mstack.begin();
	MstackType::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int, std::list<int> > s(mstack);
}

void testCopyAndAssignSimple()
{
	std::cout << YELLOW << "------- Test copy and assign: simple-------" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	std::cout << BLUE << "Printing mstack:" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << GREEN;
	for (; it != ite; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << BLUE << "MutantStack<int> mstack2(mstack)" << RESET << std::endl;
	MutantStack<int> mstack2(mstack);
	std::cout << BLUE << "MutantStack<int> mstack3 = mstack" << RESET << std::endl;
	MutantStack<int> mstack3 = mstack2;
	std::cout << BLUE << "MutantStack<int> mstack3 = mstack3" << RESET << std::endl;
	mstack3 = mstack3;
	std::cout << BLUE << "Comparing contents:" << RESET << std::endl;
	std::cout << "mstack == mstack2: " << PINK << std::boolalpha << (mstack == mstack2) << RESET << std::endl;
	std::cout << "mstack == mstack3: " << PINK << std::boolalpha << (mstack == mstack3) << RESET << std::endl;	
	if (mstack == mstack2 && mstack == mstack3)
		std::cout << GREEN << "All copies are equal" << RESET << std::endl;
	else
		std::cout << RED << "Copies are not equal" << RESET << std::endl;
	std::cout << std::endl;
}

void testCopyAndAssignComplex()
{
	std::cout << YELLOW << "------- Test copy and assign: complex-------" << RESET << std::endl;
	std::cout << BLUE << "MutantStack<int, std::list<int> >" << RESET << std::endl;
	typedef MutantStack<int, std::list<int> > MstackType;
	MstackType mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	std::cout << BLUE << "Printing mstack:" << RESET << std::endl;
	MstackType::iterator it = mstack.begin();
	MstackType::iterator ite = mstack.end();
	std::cout << GREEN;
	for (; it != ite; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << BLUE << "MutantStack<int> mstack2(mstack)" << RESET << std::endl;
	MstackType mstack2(mstack);
	std::cout << BLUE << "MutantStack<int> mstack3 = mstack" << RESET << std::endl;
	MstackType mstack3 = mstack2;
	std::cout << BLUE << "MutantStack<int> mstack3 = mstack3" << RESET << std::endl;
	mstack3 = mstack3;
	std::cout << BLUE << "Comparing contents:" << RESET << std::endl;
	std::cout << "mstack == mstack2: " << PINK << std::boolalpha << (mstack == mstack2) << RESET << std::endl;
	std::cout << "mstack == mstack3: " << PINK << std::boolalpha << (mstack == mstack3) << RESET << std::endl;	
	if (mstack == mstack2 && mstack == mstack3)
		std::cout << GREEN << "All copies are equal" << RESET << std::endl;
	else
		std::cout << RED << "Copies are not equal" << RESET << std::endl;
	std::cout << std::endl;
}
