#ifndef EASYFIND_HPP_INCLUDED
# define EASYFIND_HPP_INCLUDED

template<typename T>
typename T::iterator easyFind(T& container, int toFind);

# include "../src/easyfind.tpp"

#endif /* EASYFIND_HPP_INCLUDED */