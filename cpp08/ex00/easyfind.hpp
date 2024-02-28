#ifndef EASYFIND_H
# define EASYFIND_H

# include <iterator>
# include <algorithm>
# include <exception>

template<typename T>
typename T::iterator easyfind( T &obj, int n )
{
	typename T::iterator	itr = std::find(obj.begin(), obj.end(), n);

	if (itr == obj.end())
		throw std::runtime_error("couldn't find entered value");

	return itr;
}

#endif