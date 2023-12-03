#include <new>
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

void subject( void );

int main()
{
	// subject();

	Animal	*animal[6];

	for (int cnt = 0; cnt < 3; ++cnt)
	{
		animal[cnt] = new Dog;
		animal[cnt + 3] = new Cat; 
	}

	std::cout << std::endl;

	for (int cnt = 0; cnt < 3; ++cnt)
	{
		if (animal[cnt])
		{
			animal[cnt]->makeSound();
			delete animal[cnt];
		}
		if (animal[cnt + 3])
		{
			animal[cnt + 3]->makeSound();
			delete animal[cnt + 3];
		}
	}

	std::cout << std::endl;

	Dog	dog;
	Dog	dog_cpy;

	std::cout << std::endl;

	dog.setIdeas("animals are cute");

	dog.printIdeas();
	dog_cpy.printIdeas();

	dog_cpy = dog;

	std::cout << std::endl;

	dog.printIdeas();
	dog_cpy.printIdeas();

	std::cout << std::endl;

	return 0;
}

void subject( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
}
