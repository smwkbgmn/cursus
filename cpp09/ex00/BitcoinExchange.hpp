#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>

# include <string>
# include <exception>

// Container
# include <map>

// Validation
# include <locale>

# define NONE 0
# define FALSE 0
# define TRUE 1

typedef std::istringstream	isstream_t;
typedef std::string			str_t;
typedef std::runtime_error	err_t;

const unsigned int			monthDays[12]	= {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const str_t					headInput		= "date | value";
const str_t					headData		= "date,exchange_rate";

const str_t	errPrfx		= "Error: ";
const str_t	errMsg[]	= {
	errPrfx + "fail to read data",
	errPrfx + "fail to read input",
	errPrfx + "data has not found",
	errPrfx + "fail to get a value",
	errPrfx + "the value is out of range",
	errPrfx + "fail to open file "
};

const enum Msg {
	FAIL_RD_DATA,
	FAIL_RD_INPUT,
	NO_DATA,
	FAIL_GET_VAL,
	OUT_OF_RANGE,
	FAIL_OPN_FILE
};

class BitcoinExchange {
	private:
		enum FileType {
			DATA,
			INPUT
		};

		struct 	FileStream;
		struct	Date;
		
		typedef struct FileStream		file_s;
		typedef struct Date				date_s;
		typedef std::map<date_s, float>	map_t;


	public:
		BitcoinExchange( const str_t& );
		~BitcoinExchange( void );

		void		outResult( const str_t& ) const;

	private:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange & );

		map_t		_rate;		

		static bool	_success( const isstream_t& );

		void		_getData( const str_t& );
		void		_insertData( isstream_t );
		void		_printResult( isstream_t ) const;
		date_s		_getDate( isstream_t&, FileType ) const;
		float		_getValue( isstream_t&, FileType ) const;
		void		_throwInvalidValue( float ) const;

		BitcoinExchange	&operator=( const BitcoinExchange & );

	private:
		struct FileStream {
			FileStream( const str_t& );
			~FileStream( void );

			std::ifstream	in;
		};

		struct Date {
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

			typedef unsigned int	bits_t;

			Date( const str_t& );

			bits_t	date;
			/* Y: 14bits, M: 4bits, D: 5bits */

			void	convert( const str_t& );
			bits_t	toBits( const str_t&, int ) const;
			bits_t	padBits( bits_t, int ) const;
			bool	validDay( void ) const;
			bool	yearLeap( bits_t ) const;
			void	print( void ) const;
			void	throwInvalidValue( bits_t, unsigned int, unsigned int ) const;

			bool	operator<( const Date& ) const;
		};

		struct invalidDateExcpt: err_t { invalidDateExcpt( void ); };
};
#endif