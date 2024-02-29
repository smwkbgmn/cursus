#ifndef OCF_HPP
# define OCF_HPP

# include <iostream>

class OCF
{
	/* TYPEDEF & STRUCTURE */

	/* DATA */

	/* INSTANTIATE */
	public:
		OCF( void );
		OCF( const OCF & );
		~OCF( void );

	/* MEMBER*/
	public:

	/* OPERATOR */
	public:
		OCF	&operator=( const OCF & );
};

#endif