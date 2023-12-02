#include <new>
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

void subject( void );

int main()
{
	subject();
	
	return 0;
}

void subject( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();

	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}