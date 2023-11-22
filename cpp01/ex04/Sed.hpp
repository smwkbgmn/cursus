#ifndef SED_HPP
# define SED_HPP

# include "FileStream.hpp"

class Sed
{
	public:
		Sed( const str_t &, const str_t &, const str_t & );

		void	proceed( void );

	private:
		FileStream	_fs;
		str_t		_target;
		str_t		_replace;
};

#endif