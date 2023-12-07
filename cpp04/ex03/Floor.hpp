#ifndef FLOOR_HPP
# define FLOOR_HPP

# define FALSE 0
# define TRUE 1

# define SIZE_FLOOR 5

class AMateria;

struct Floor
{
	AMateria	*_space[SIZE_FLOOR];
	int			_idx;
	
	Floor( void );
	~Floor( void );

	void	initSpace( void );
	void	freeSpace( void );
	
	bool	drop( AMateria * );
};

#endif