#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		std::string	&getName( void );

		void	announce( void );

	private:
		static int	_idx;
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif