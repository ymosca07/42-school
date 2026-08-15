#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    n  = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=( const Fixed& rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits( void ) const {
    return n;
}

void Fixed::setRawBits( int const raw ) {
    this->n = raw;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->n = n << 8;
}

int Fixed::toInt( void ) const {
    return this->n >> 8;
}

Fixed::Fixed (const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->n = roundf(f * 256);
}

float Fixed::toFloat( void ) const {
    return (float)this->n / 256;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}