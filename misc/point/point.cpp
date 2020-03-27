#include <cmath>
#include "point.h"

point::point()
{
}

point::point(int xpos, int ypos)
{
    x = xpos;
    y = ypos;
}

point::~point()
{
}

int point::get_x() const
{
    return x;
}

int point::get_y() const
{
    return y;
}

double point::len() const
{
    return sqrt(x*x + y*y);
}

point& point::operator+=(const point& rhs)
{
    x += rhs.x;
    return *this;
}

point& point::operator-=(const point& rhs)
{
    x -= rhs.x;
    return *this;
}

point& point::operator++()
{
    x++;
    y++;
    return *this;
}
point point::operator++(const int i)
{
    point tmp(*this);
    operator++();
    return tmp;
}

point& point::operator--()
{
    x--;
    y--;
    return *this;
}
point point::operator--(const int i)
{
    point tmp(*this);
    operator--();
    return tmp;
}

point operator+(const point& lhs, const point& rhs)
{
    return point(lhs.x + rhs.x, lhs.y + rhs.y);
}

point operator-(const point& lhs, const point& rhs)
{
    return point(lhs.x - rhs.x, lhs.y - rhs.y);
}

bool operator==(const point& lhs, const point& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const point& lhs, const point& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const point& lhs, const point& rhs)
{
    return lhs.len() < rhs.len();
}

bool operator>(const point& lhs, const point& rhs)
{
    return rhs < lhs;
}

bool operator<=(const point& lhs, const point& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const point& lhs, const point& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& out, const point &p)
{
    return out << "(" << p.x << ", " << p.y << ")";
}

std::istream& operator>>(std::istream& in, point &p)
{
    int x;
    int y;
    in >> x >> y;
    p = point(x, y);
    return in;
}
