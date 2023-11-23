#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
		Harl( void );

		void	complain( std::string );

	private:
		std::string	_level[4];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif