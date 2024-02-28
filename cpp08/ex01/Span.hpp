#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <set>
# include <algorithm>

class Span
{
	public:
		struct exceedSizeExcpt: std::runtime_error{ exceedSizeExcpt( void ); };
		struct duplicationExcpt: std::runtime_error { duplicationExcpt( void ); };
		struct noSpanExcpt: std::runtime_error { noSpanExcpt( void ); };

	public:
		Span( void );
		Span( const Span& );
		explicit Span( unsigned int );
		~Span( void );

		Span&	operator=( const Span& );
		
		void			addNumber( int );
		void			addNumber( std::set<int>::iterator, std::set<int>::iterator );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

	private:
		unsigned int	_size;
		std::set<int>	_elem;

	private:
		
		void	throwExceedSize( void ) const;
		void	throwDuplication( int ) const;
		void	throwNoSpan( void ) const;
};

#endif