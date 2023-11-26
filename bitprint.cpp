#include <bitset>
#include <iostream>

void bitprint( int n )
{
	std::cout << "bitprint for int\n";
	std::bitset<sizeof(int) * 8> binaryRepresentation(n);
	std::cout << binaryRepresentation << std::endl;
}

void bitprint( float fl )
{
	int	fl_bit;

	std::cout << "bitprint for fl\n";
	std::memcpy(&fl_bit, &fl, sizeof(float));
	std::bitset<sizeof(float) * 8> binaryRepresentation(fl_bit);
	std::cout << binaryRepresentation << std::endl;
}

// Fixed::Fixed( const float fl )
// {
// 	float	frac;

// 	_fp = (int)roundf(fl);
// 	if (_fp > fl)
// 		_fp -= 1;
// 	frac = abs(fl - _fp);

// 	for (int pos = 0; pos < _bitFrac; ++pos)
// 	{
// 		_fp <<= 1;
// 		frac *= 2;
// 		if (frac >= 1 )
// 		{
// 			_fp += 0b1;
// 			frac -= 1;
// 		}
// 	}

// 	std::cout << "CopyFloat constructor called\n";
// }

// float Fixed::toFloat( void ) const
// {
// 	float	frac = 0;

// 	for (int pos = 0; pos < _bitFrac; ++pos)
// 	{
// 		if ((_fp >> pos) & 0b1)
// 			frac += ((float)1 / (0b1 << (_bitFrac - pos)));
// 	}

// 	return ((float)toInt() + frac);
// }
