#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
  std::cout << "Copy constructor called" << std::endl;
  this->_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
      this->_value = other._value;
  return *this;
}


Fixed::Fixed(const int number)
{
  std::cout << "Int constructor called" << std::endl;
  this->_value = number << _fractionalBits;
}

Fixed::Fixed(const float number)
{
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(number * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
  return (float)this->_value / (1 <<_fractionalBits);
}

int Fixed::toInt(void) const
{
  return this->_value >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}

void Fixed::setRawBits(int const raw)
{
  this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
  out << fixed.toFloat();
  return out;
}
