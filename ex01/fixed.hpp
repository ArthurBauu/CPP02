#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>


class Fixed 
{
private:
	int _fixvalue;
	const static int _fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	Fixed (const int n);
	Fixed (const float f);


	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

};

std::ostream &operator<<(std::ostream &ut, const Fixed &value);

#endif