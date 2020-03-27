#include <iostream>
#include <ostream>
#include <istream>

class point {
    private:
        int x;
        int y;
    public:
        point();
        point(int, int);
        ~point();
        int get_x() const;
        int get_y() const;
        double len() const;

        point& operator+=(const point&);
        point& operator-=(const point&);

        point& operator++();
        point operator++(const int);

        point& operator--();
        point operator--(const int);

        friend point operator+(const point&, const point&);
        friend point operator-(const point&, const point&);
        friend bool operator==(const point&, const point&);
        friend bool operator!=(const point&, const point&);
        friend bool operator< (const point&, const point&);
        friend bool operator> (const point&, const point&);
        friend bool operator<=(const point&, const point&);
        friend bool operator>=(const point&, const point&);
        friend std::ostream& operator<<(std::ostream& out, const point& p);
        friend std::istream& operator>>(std::istream& in, point& p);
};
