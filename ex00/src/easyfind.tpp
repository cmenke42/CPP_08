#include <algorithm>

/**
 * @brief Searches for first occurrence of toFind in container
 * 
 * @tparam T Container type
 * @param container 
 * @param toFind 
 * @return T::iterator  -> Iterator to the first occurrence of toFind in container. 
 *                      If toFind is not found, returns container.end()
 */
template<typename T>
typename T::iterator easyFind(T& container, int toFind)
{
    return (std::find(container.begin(), container.end(), toFind));
}
