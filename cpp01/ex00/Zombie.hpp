#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie( std::string );
		~Zombie( void );

		void	announce( void );

	private:
		std::string	name;
};

#endif