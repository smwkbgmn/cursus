#ifndef OCF_HPP
# define OCF_HPP

# include <iostream>

class OCF
{
	public:
		OCF( void );
		OCF( const OCF & );
		~OCF( void );

		OCF	&operator=( const OCF & );
};

#endif