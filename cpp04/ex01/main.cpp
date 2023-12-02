#include <new>
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

void subject( void );

int main()
{
	// subject();

	Animal	*animal = new Animal[10];

	animal[0] = Dog();
	animal[5] = Cat();


	return 0;
}

void subject( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
}
