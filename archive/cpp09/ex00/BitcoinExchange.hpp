#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/* Container */
# include <map>

# include "File.hpp"
# include "Date.hpp"

enum FileType {
	DATA,
	INPUT
};

typedef std::map<Date, float>	map_t;

const str_t	headInput	= "date | value";
const str_t	headData	= "date,exchange_rate";

class BitcoinExchange {
	public:
		BitcoinExchange( const str_t& );
		~BitcoinExchange( void );

		void	outResult( const str_t& ) const;

	private:
		map_t	_rate;

		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange & );

		void	_getData( const str_t& );
		void	_insertData( const str_t& );
		void	_printResult( const str_t& ) const;
		Date	_getDate( isstream_t&, FileType ) const;
		float	_getValue( isstream_t&, FileType ) const;
		void	_throwInvalidValue( float ) const;
		bool	_success( const isstream_t& ) const;

		BitcoinExchange	&operator=( const BitcoinExchange & );
};

#endif