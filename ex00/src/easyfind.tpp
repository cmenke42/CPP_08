template<typename T>
typename T::iterator easyFind(T& container, int toFind)
{
    return (std::find(container.begin(), container.end(), toFind));
}
