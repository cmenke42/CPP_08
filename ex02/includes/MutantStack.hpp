#ifndef MUTANT_STACK_HPP_INCLUDED
# define MUTANT_STACK_HPP_INCLUDED

# include <stack>

template <typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence>
{
	public:
		typedef typename Sequence::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif /* MUTANT_STACK_HPP_INCLUDED# */