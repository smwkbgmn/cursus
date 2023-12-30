#include <new>
#include <iostream>

// #include "ICharacter.hpp"
#include "Floor.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

Floor	Character::_floor;

Character::Character( void )
{
	initInven();

	std::cout << "[CON-DEF] Character has created" << std::endl;
}

Character::Character( const str_t &name )
: _name( name )
{
	initInven();
	
	std::cout << "[CON-NME] Character has created" << std::endl;
}

Character::Character( const Character &target )
{
	initInven();
	*this = target;
	
	std::cout << "[CON-CPY] Character has created" << std::endl;
}

Character::~Character( void )
{
	freeInven();

	std::cout << "[DES] Character has destroyed" << std::endl;
}

Character &Character::operator=( const Character &target )
{
	std::cout << "[Character's copy assignment called]" << std::endl;

	if ( this != &target )
	{
		_name = target.getName();
		copyInven( target );
	}

	return *this;
}

const str_t	&Character::getName( void ) const
{
	return _name;
}

void	Character::equip( AMateria* m )
{
	int	idx;

	if ( m && _floor.drop( m ) )
	{
		for ( idx = 0; idx < SIZE_INVEN && _inven[idx]; ++idx );

		if ( idx < SIZE_INVEN )
		{
			std::cout << _name << " equiped a(an) " << m->getType();
			std::cout << " to the inventory " << idx << std::endl;

			_inven[idx] = m;
		}
	}
}

void	Character::unequip( int idx )
{
	if ( idx < SIZE_INVEN && _inven[idx] )
	{
		std::cout << _name << " unequiped a(an) " << _inven[idx]->getType() << std::endl;
		_inven[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if ( idx < SIZE_INVEN && _inven[idx] )
		_inven[idx]->use( target );
}

void Character::initInven( void )
{
	for ( int idx = 0; idx < SIZE_INVEN; ++idx )
		_inven[idx] = NULL;
}

void Character::freeInven( void )
{
	for ( int idx = 0; idx < SIZE_INVEN; ++idx )
		if ( _inven[idx] )
			_floor.remove( _inven[idx] );
			
	initInven();
}

void Character::copyInven( const Character &target )
{
	freeInven();

	for ( int idx = 0; idx < SIZE_INVEN; ++idx )
	{
		if ( target._inven[idx] )
		{
			_inven[idx] = target._inven[idx]->clone();

			if ( !_floor.drop( _inven[idx] ) )
				_inven[idx] = NULL;
		}
	}
}