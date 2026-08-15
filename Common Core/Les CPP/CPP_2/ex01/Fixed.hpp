#include <iostream>
#include <cmath>

class Fixed {
    private:
        int n;
        static const int j = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed( const Fixed& src );
        Fixed& operator=( const Fixed& rhs );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed(const int n);
        Fixed (const float f);
        int toInt( void ) const;
        float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);