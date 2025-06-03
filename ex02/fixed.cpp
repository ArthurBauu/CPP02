#include "fixed.hpp"

Fixed::Fixed() : _fixvalue(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixvalue = other._fixvalue;
	return *this;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixvalue = n << _fractionalBits; // Convert int to fixed-point
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_fixvalue = static_cast<int>(roundf(f * (1 << _fractionalBits))); // Convert float to fixed-point
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixvalue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixvalue = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_fixvalue) / (1 << _fractionalBits); 
}

int Fixed::toInt() const
{
	return _fixvalue >> _fractionalBits; 
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _fixvalue > other._fixvalue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _fixvalue < other._fixvalue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _fixvalue >= other._fixvalue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _fixvalue <= other._fixvalue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _fixvalue == other._fixvalue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _fixvalue != other._fixvalue;
}


Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed().setRawBits(this->_fixvalue + other._fixvalue), *this;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed().setRawBits(this->_fixvalue - other._fixvalue), *this;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed().setRawBits((this->_fixvalue * other._fixvalue) >> _fractionalBits), *this;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._fixvalue == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	return Fixed().setRawBits((this->_fixvalue << _fractionalBits) / other._fixvalue), *this;
}