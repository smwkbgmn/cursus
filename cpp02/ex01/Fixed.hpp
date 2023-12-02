#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed & );
		~Fixed( void );

		Fixed	&operator=( const Fixed & );

		int		getRawBits( void ) const;
		void	setRawBits( int const );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		static const int	_bitFrac = 8;

		int	_fp;
};

std::ostream &operator<<( std::ostream &, const Fixed & );

#endif