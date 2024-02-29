#include <iostream>
#include <list>

#include "MutantStack.hpp"

void myStack( void );
void stdList( void );

int main()
{
	myStack();
	std::cout << std::endl;

	stdList();
	std::cout << std::endl;

	return 0;
}

void myStack( void ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void stdList( void ) {
	std::list<int> slist;

	slist.push_back(5);
	slist.push_back(17);
	std::cout << slist.back() << std::endl;
	slist.pop_back();
	std::cout << slist.size() << std::endl;
	slist.push_back(3);
	slist.push_back(5);
	slist.push_back(737);
	slist.push_back(0);

	std::list<int>::iterator it = slist.begin();
	std::list<int>::iterator ite = slist.end();
	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(slist);	
}