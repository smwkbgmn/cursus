#include <iostream>

// #include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

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
	int	cnt;

	if ( m )
	{
		for ( cnt = 0; cnt < SIZE_INVEN && _inven[cnt]; ++cnt );
		
		if ( cnt != SIZE_INVEN )
		{
			_inven[cnt] = m;
			_inven[cnt]->setEquip( TRUE );

			std::cout << _name << " equiped a(an) " << m->getType();
			std::cout << " to the inventory " << cnt << std::endl;
		}

		/* Equip doesn't have any return value so the main has no way to know if equipment
		success or not. It means that the pointer to Meteria should be managed in main.
		but in this condition, it may has an possibility of double free */
	}
}

void	Character::unequip( int idx )
{
	str_t	type_del;

	if ( _inven[idx] )
	{
		type_del = _inven[idx]->getType();

		_inven[idx]->setEquip( FALSE );
		_inven[idx] = NULL;
		
		std::cout << _name << " unequiped a(an) " << type_del << std::endl;
		// if ( _floor.drop( _inven[idx] ) )
		// {
		// 	_inven[idx] = NULL;

		// 	std::cout << _name << " unequiped a(an) " << type_del << std::endl;
		// }
		// else
		// 	std::cout << "Materias are already everywhere on the floor!" << std::endl;
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if ( _inven[idx] )
		_inven[idx]->use( target );
}

void Character::initInven( void )
{
	for ( int cnt = 0; cnt < SIZE_INVEN; ++cnt )
		_inven[cnt] = NULL;
}

void Character::freeInven( void )
{
	for ( int cnt = 0; cnt < SIZE_INVEN; ++cnt )
		if ( _inven[cnt] )
			delete _inven[cnt];
}

void Character::copyInven( const Character &target )
{
	for ( int cnt = 0; cnt < SIZE_INVEN; ++cnt )
	{
		if ( _inven[cnt] )
			delete _inven[cnt];

		if ( target._inven[cnt] )
			_inven[cnt] = target._inven[cnt]->clone();
		else
			_inven[cnt] = NULL;
	}
}