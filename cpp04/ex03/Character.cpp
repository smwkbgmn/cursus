#include <iostream>

#include "Character.hpp"

Character::Character( void )
{
	initInven();

	std::cout << "[CON-DEF] Character has created" << std::endl;
}

Character::Character( const str_t &name )
: _name(name)
{
	initInven();
	
	std::cout << "[CON-NMP] Character has created" << std::endl;
}

Character::Character( const Character &target )
{
	*this = target;
	
	std::cout << "[CON-CPY] Character has created" << std::endl;
}

Character::~Character( void )
{
	std::cout << "[DES] Character has destroyed" << std::endl;
}

Character &Character::operator=( const Character &target )
{
	std::cout << "[Character's copy assignment called]" << std::endl;

	if (this != &target)
	{
		_name = target.getName();
		copyInven();
	}
}

str_t	&Character::getName( void ) const
{
	return _name;
}

void	Character::equip( AMateria* m )
{
	for (int cnt = 0; cnt < 4; ++cnt)
	{
		if (!_inven[cnt])
		{
			_inven[cnt] = m;
			break ;
		}
	}
}

void	Character::unequip( int idx )
{
	
}

void	Character::use( int idx, ICharacter& target )
{
	
}

void Character::initInven( void )
{
	for (int cnt = 0; cnt < 4; ++cnt)
		_inven[cnt] = NULL;
}

void Character::copyInven( const Character &target )
{
	for (int cnt = 0; cnt < 4; ++cnt)
	{
		if (_inven[cnt])
			delete _inven[cnt];
		if (target.)
	}
}
