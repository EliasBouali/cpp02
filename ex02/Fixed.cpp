
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
  return (float)this->_value / (1 << _fractionalBits);
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

bool Fixed::operator>(const Fixed &other) const
{
  return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
  return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
  return this->_value <= other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
  return this->_value >= other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
  return this->_value != other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
  return this->_value == other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
  Fixed result;
  result.setRawBits(this->_value + other._value);
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed result;
  result.setRawBits(this->_value - other._value);
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed result;
  long tmp = ((long)this->_value * (long)other._value);
  tmp >>= _fractionalBits;
  result.setRawBits((int)tmp);
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed result;
  if (other._value == 0)
  {
    std::cerr << "Error: division by zero in Fixed::operator/." << std::endl;
    result.setRawBits(0);
    return result;
  }
  long tmp = ((long)this->_value << _fractionalBits) / other._value;
  result.setRawBits((int)tmp);
  return result;
}

Fixed &Fixed::operator++()
{
    ++(this->_value);
    return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed tmp(*this);
  ++(this->_value);
  return tmp;
}

Fixed &Fixed::operator--()
{
  --(this->_value);
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed tmp(*this);
  --(this->_value);
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
  if (a < b)
    return a;
  else
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  if (a < b)
    return a;
  else
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
  if (a > b)
    return a;
  else
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  if (a > b)
    return a;
  else
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
  out << fixed.toFloat();
  return out;
}
