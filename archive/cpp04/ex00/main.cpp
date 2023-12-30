#include <new>
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void subject( void );

int main()
{
	subject();
	
	std::cout << std::endl;

	const WrongAnimal *wrong = new WrongCat();
	wrong->makeSound();

	std::cout << std::endl;

	delete wrong;

	return 0;
}

void subject( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();	
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();

	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
}
