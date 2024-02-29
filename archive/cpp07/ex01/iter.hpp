#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter( T *ptr, const size_t len, void (*fp)( T & ))
{
	for (size_t idx = 0; idx < len; ++idx)
		fp(ptr[idx]);
}

template<typename T>
void iter( const T *ptr, const size_t len, void (*fp)( const T & ))
{
	for (size_t idx = 0; idx < len; ++idx)
		fp(ptr[idx]);
}

#endif