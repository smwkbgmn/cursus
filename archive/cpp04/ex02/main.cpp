#include <new>
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// AAnimal	animal; // <- Can not instantiate
	Dog	dog;
	Cat	cat;

	dog.makeSound();
	cat.makeSound();

	dog.setIdeas("hello");
	dog.printIdeas();

	return 0;
}
