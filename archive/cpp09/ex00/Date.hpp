#ifndef DATE_HPP
# define DATE_HPP

# include <sstream>
# include <iostream>
# include <iomanip>

# include <string>
# include <exception>

# include <locale>

# include "error.hpp"

# define NONE 0
# define FALSE 0
# define TRUE 1

typedef unsigned int		bits_t;

typedef std::istringstream	isstream_t;
typedef std::ostream		ostream_t;
typedef std::string			str_t;
typedef std::runtime_error	err_t;

const unsigned int	monthDays[12]	= {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class Date {
	public:
		Date( void );
		Date( const Date& );
		Date( const str_t& );
		~Date( void );

		bits_t	year( void ) const;
		bits_t	month( void ) const;
		bits_t	day( void ) const;

		Date&	operator=( const Date& );
		bool	operator<( const Date& ) const;

	private:
		enum ID { Y, M, D };
		enum Padding {
			PAD_Y = 9,
			PAD_M = 5,
			PAD_D = 0
		};

		enum Holder {
			HLD_Y = 0b11111111111111,
			HLD_M = 0b1111,
			HLD_D = 0b11111
		};

		bits_t	_date;
		/* Y: 14bits, M: 4bits, D: 5bits */

		void	_convert( const str_t& );
		bits_t	_toBits( const str_t&, int ) const;
		bits_t	_padBits( bits_t, int ) const;
		bool	_validDay( void ) const;
		bool	_yearLeap( bits_t ) const;
		bool	_success( const isstream_t& ) const;
		void	_throwInvalidForm( const str_t&, int ) const;
		void	_throwInvalidValue( bits_t, unsigned int, unsigned int ) const;

	public:
		struct invalidDateExcpt: err_t { invalidDateExcpt( void ); };
};

ostream_t&	operator<<( ostream_t&, const Date& );

#endif