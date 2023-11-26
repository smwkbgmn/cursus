#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed & );
		Fixed( const int );
		Fixed( const float );
		~Fixed( void );

		Fixed	&operator=( const Fixed & );

		bool	operator>( const Fixed & ) const;
		bool	operator<( const Fixed & ) const;
		bool	operator>=( const Fixed & ) const;
		bool	operator<=( const Fixed & ) const;
		bool	operator==( const Fixed & ) const;
		bool	operator!=( const Fixed & ) const;

		Fixed	operator+( const Fixed & ) const;
		Fixed	operator-( const Fixed & ) const;
		Fixed	operator*( const Fixed & ) const;
		Fixed	operator/( const Fixed & ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const );

		static Fixed		&min(Fixed &, Fixed & );
		static const Fixed	&min(const Fixed &, const Fixed & );
		static Fixed		&max(Fixed &, Fixed & );
		static const Fixed	&max(const Fixed &, const Fixed & );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		static const int	_bitFrac = 8;

		int	_fp;
};

#endif