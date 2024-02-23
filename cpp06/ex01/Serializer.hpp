#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>

struct Data;

class Serializer
{
	public:
		static uintptr_t	serialize( Data * );
		static Data			*deserialize( uintptr_t );

	private:
		Serializer( void );
		Serializer( Serializer & );
		~Serializer( void );

		Serializer	operator=( const Serializer & );
};

#endif