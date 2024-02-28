#include <iostream>
#include <vector>
#include <stack>
#include <list>

#include "easyfind.hpp"

int main( void )
{
	std::vector<int>	elem;
	for (int n = 0; n < 5; ++n)
		elem.push_back(n);

	std::vector<int>	vec(elem);
	std::deque<int>		deq(elem.begin(), elem.end());
	std::list<int>		lst(elem.begin(), elem.end());

	try
	{
		std::cout << std::distance(vec.begin(), easyfind(vec, 3)) << std::endl;
		std::cout << std::distance(deq.begin(), easyfind(deq, 3)) << std::endl;
		std::cout << std::distance(lst.begin(), easyfind(lst, 3)) << std::endl;
	}
	catch (std::exception &excpt)
	{
		std::cout << excpt.what() << std::endl;
	}

	try
	{
		std::cout << std::distance(vec.begin(), easyfind(vec, 5)) << std::endl;
		std::cout << std::distance(deq.begin(), easyfind(deq, 5)) << std::endl;
		std::cout << std::distance(lst.begin(), easyfind(lst, 5)) << std::endl;
	}
	catch (std::exception &excpt)
	{
		std::cout << excpt.what() << std::endl;
	}

	return 0;
}