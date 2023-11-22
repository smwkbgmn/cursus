#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie( std::string );
		~Zombie( void );

		std::string	&getName( void );

		void	announce( void );
		Zombie	*newZombie( std::string );
		void	randomChump( std::string );

	private:
		std::string	name;
};

Zombie	*newZombie( std::string name );
void 	randomChump( std::string name );

#endif