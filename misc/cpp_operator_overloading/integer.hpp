/**
 * Simple class to demonstrate operator overloading
 */
#include <cstddef>
#include <ostream>
#include <istream>

class Int
{
private:
    int _i;
public:
    Int(int i) : _i(i) {}

    Int& operator++()       { _i++; return *this; }
    Int  operator++(int)    { Int tmp(*this); operator++(); return tmp; }

    Int& operator--()       { _i--; return *this; }
    Int  operator--(int)    { Int tmp(*this); operator--(); return tmp; }

    Int& operator+=(const Int& rhs)     { _i += rhs._i; return *this; }
    Int& operator-=(const Int& rhs)     { _i -= rhs._i; return *this; }
    Int& operator*=(const Int& rhs)     { _i *= rhs._i; return *this; }
    Int& operator/=(const Int& rhs)     { _i /= rhs._i; return *this; }
    friend Int operator+(Int lhs, const Int& rhs)   { lhs += rhs; return lhs; }
    friend Int operator-(Int lhs, const Int& rhs)   { lhs -= rhs; return lhs; }
    friend Int operator*(Int lhs, const Int& rhs)   { lhs *= rhs; return lhs; }
    friend Int operator/(Int lhs, const Int& rhs)   { lhs /= rhs; return lhs; }

    // relational operators
    inline bool operator< (const Int& rhs) { return _i < rhs._i; }
    inline bool operator> (const Int& rhs) { return operator<(rhs); }
    inline bool operator<=(const Int& rhs) { return !operator>(rhs); }
    inline bool operator>=(const Int& rhs) { return !operator<(rhs); }

    inline bool operator==(const Int& rhs) { return _i == rhs._i; }
    inline bool operator!=(const Int& rhs) { return !operator==(rhs); }

    // array subscript operators
    Int&       operator[](size_t index);
    const Int& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& o, const Int& i);
    friend std::istream& operator>>(std::istream& o, const Int& i);
};
