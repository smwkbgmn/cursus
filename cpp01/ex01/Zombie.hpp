#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		std::string	getName( void ) const;
		void		setName( const std::string & );

		void	announce( void );

	private:
		static int	_idx;
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif