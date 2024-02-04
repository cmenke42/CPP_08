#include "Span.hpp"

/**
 * @brief Inserts a range into the Span.
 *
 * @tparam Iterator Any iterator type.
 * @param first begin of range to add.
 * @param last End of range to add.
 * @throws std::runtime_error -> If Span can't accommodate the range.
 * 
 * @note Undefined behavior if first and last form an invalid range.
 */
template <typename Iterator>
void Span::addNumber(Iterator first, Iterator last)
{
    std::ptrdiff_t distance = std::distance(first, last);

    if (distance + this->_array.size() > this->_maxSize)
        throw std::runtime_error("Span is too small to take this range");

    this->_array.insert(this->_array.end(), first, last);
}
