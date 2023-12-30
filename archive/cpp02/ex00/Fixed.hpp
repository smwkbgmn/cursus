#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed & );
		~Fixed( void );

		Fixed	&operator=( const Fixed & );

		int		getRawBits( void ) const;
		void	setRawBits( int const );

	private:
		static const int	_bitFrac = 8;

		int	_fp;
};

#endif