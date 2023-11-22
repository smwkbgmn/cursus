#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie( void );
		Zombie( std::string );
		~Zombie( void );

		std::string	&getName( void );

		void	announce( void );
		Zombie	*newZombie( std::string );
		void	randomChump( std::string );

	private:
		static int	_idx;
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif