#include "integer.h"

integer::integer() : i(0) {}
integer::integer(int x) : i(x) {}
integer::~integer() {}

integer& integer::operator+=(const integer& rhs)
{
    i += rhs.i;
    return *this;
}

integer operator+(const integer& lhs, const integer& rhs)
{
    integer tmp(lhs);
    tmp += rhs;
    return tmp;
}

integer& integer::operator-=(const integer& rhs)
{
    i -= rhs.i;
    return *this;
}

integer operator-(const integer& lhs, const integer& rhs)
{
    integer tmp(lhs);
    tmp -= rhs;
    return tmp;
}

integer& integer::operator+=(int rhs)
{
    i += rhs;
    return *this;
}

integer operator+(const integer& lhs, int rhs)
{
    integer tmp(lhs);
    tmp += rhs;
    return tmp;
}

integer& integer::operator-=(int rhs)
{
    i -= rhs;
    return *this;
}

integer operator-(const integer& lhs, int rhs)
{
    integer tmp(lhs);
    tmp -= rhs;
    return tmp;
}

integer& integer::operator++()
{
    i++;
    return *this;
}

integer integer::operator++(int i)
{
    integer tmp(*this);
    operator++();
    return tmp;
}

integer& integer::operator--()
{
    i--;
    return *this;
}

integer integer::operator--(int i)
{
    integer tmp(*this);
    operator--();
    return tmp;
}

bool operator==(const integer& lhs, const integer& rhs) { return lhs.i == rhs.i; 	}
bool operator!=(const integer& lhs, const integer& rhs) { return !(lhs.i == rhs.i); }
bool operator< (const integer& lhs, const integer& rhs) { return lhs.i < rhs.i; 	}
bool operator> (const integer& lhs, const integer& rhs) { return rhs < lhs;     	}
bool operator<=(const integer& lhs, const integer& rhs) { return !(lhs > rhs);  	}
bool operator>=(const integer& lhs, const integer& rhs) { return !(lhs < rhs);  	}

std::ostream& operator<<(std::ostream& out, const integer& ip)
{
    out << ip.i;
    return out;
}

std::istream& operator>>(std::istream& in, integer& ip)
{
    in >> ip.i;
    return in;
}
