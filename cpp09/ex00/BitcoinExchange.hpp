#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>

# include <exception>
# include <string>

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

static const unsigned int	monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const str_t			headInput = "date | value";
static const str_t			errPrfx = "Error: ";

class BitcoinExchange
{
	private:
		struct 	FileStream;
		struct	Date;
		
		typedef struct FileStream		file_s;
		typedef struct Date				date_s;
		typedef std::map<date_s, float>	data_t;

		enum FileType {
			DATA,
			INPUT
		};

	public:
		BitcoinExchange( const str_t& );
		~BitcoinExchange( void );

		void	outResult( const str_t& ) const;

	private:
		data_t	_rate;		

		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange & );

		static bool	success( const isstream_t& );

		void	getData( const str_t& );
		void	insertData( isstream_t );
		void	printResult( isstream_t ) const;
		date_s	getDate( isstream_t&, FileType ) const;
		float	getValue( isstream_t&, FileType ) const;
		void	throwInvalidValue( float ) const;

		BitcoinExchange	&operator=( const BitcoinExchange & );

	private:
		struct FileStream {
			std::ifstream	_in;

			FileStream( const str_t& );
			~FileStream( void );
		};

		struct Date {
			typedef unsigned int	bits_t;

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

			Date( const str_t& );

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