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
	Fixed (int raw, bool);

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

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;



};

std::ostream &operator<<(std::ostream &ut, const Fixed &value);

#endif