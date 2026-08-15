#include <iostream>

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
};