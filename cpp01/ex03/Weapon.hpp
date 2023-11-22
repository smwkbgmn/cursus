#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon( std::string );

		const std::string	&getType( void );
		void				setType( const std::string & );

	private:
		std::string type;
};

#endif