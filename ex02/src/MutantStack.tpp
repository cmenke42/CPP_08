#include "MutantStack.hpp"

template <typename T, typename Sequence>
MutantStack<T, Sequence>::MutantStack()
                         : std::stack<T, Sequence>()
{
}

template <typename T, typename Sequence>
MutantStack<T, Sequence>::MutantStack(const MutantStack& other)
                         : std::stack<T, Sequence>(other)
{
}

template <typename T, typename Sequence>
MutantStack<T, Sequence>& MutantStack<T, Sequence>::operator=(const MutantStack& other)
{
	if (this != &other) 
        std::stack<T, Sequence>::operator=(other);
    return (*this);
}

template <typename T, typename Sequence>
MutantStack<T, Sequence>::~MutantStack() {}


template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::iterator MutantStack<T, Sequence>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Sequence>
typename MutantStack<T, Sequence>::iterator MutantStack<T, Sequence>::end()
{
	return (this->c.end());
}
