#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

typedef std::string	str_t;

class AMateria;

class IMateriaSource
{
	public:
		virtual	~IMateriaSource( void ) {}

		virtual	void		learnMateria( AMateria * ) = 0;
		virtual	AMateria*	createMateria( str_t const &type ) = 0;
};

#endif