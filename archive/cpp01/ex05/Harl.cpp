#include <iostream>

#include "Harl.hpp"

Harl::Harl( void )
{
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";

	_complain[0] = &Harl::debug;
	_complain[1] = &Harl::info;
	_complain[2] = &Harl::warning;
	_complain[3] = &Harl::error;
}

void	Harl::complain( std::string level )
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (_level[idx] == level)
		{
			(this->*_complain[idx])();
			break ;
		}
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\n"
		<< "I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!\n"
		<< "I want to speak to the manager now." << std::endl;
}