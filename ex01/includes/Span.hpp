#ifndef SPAN_HPP_INCLUDED
# define SPAN_HPP_INCLUDED

#include <vector>
#include <stdexcept>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& 						operator=(const Span& other);
		~Span();


		void						addNumber(unsigned int number);
		template <typename Iterator>
		void 						addNumber(Iterator first, Iterator last);
		unsigned int				shortestSpan() const;
		unsigned int				longestSpan() const;

		void						print() const;
	private:
		typedef std::vector<unsigned int> _ArrayType;
		Span::_ArrayType 			_array;
		unsigned int				_maxSize;

		static void 				_printValue(const unsigned int& value);

};

#include "Span.tpp"

#endif /* SPAN_HPP_INCLUDED */