#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <set>
# include <algorithm>

class Span
{
	public:
		typedef std::set<int>::iterator	iterator;

		struct exceedSizeExcpt: std::runtime_error{ exceedSizeExcpt( void ); };
		struct duplicationExcpt: std::runtime_error { duplicationExcpt( void ); };
		struct noSpanExcpt: std::runtime_error { noSpanExcpt( void ); };
		
	public:
		Span( void );
		Span( const Span& );
		explicit Span( unsigned int );
		~Span( void );

	public:
		void			addNumber( int );
		void			addNumber( iterator, iterator );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

	public:
		Span&	operator=( const Span& );

	private:
		unsigned int	_size;
		std::set<int>	_elem;

	private:	
		void	throwExceedSize( void ) const;
		void	throwDuplication( int ) const;
		void	throwNoSpan( void ) const;
};

#endif