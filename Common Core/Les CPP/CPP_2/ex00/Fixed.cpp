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
    std::cout << "getRawBits member function called" << std::endl;
    return n;
}

void Fixed::setRawBits( int const raw ) {
    this->n = raw;
}