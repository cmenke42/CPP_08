#ifndef EASYFIND_HPP_INCLUDED
# define EASYFIND_HPP_INCLUDED

# include <algorithm>

template<typename T>
typename T::iterator easyFind(T& container, int toFind);

# include "easyfind.tpp"

#endif /* EASYFIND_HPP_INCLUDED */