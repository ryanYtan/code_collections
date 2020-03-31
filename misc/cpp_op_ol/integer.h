#include <ostream>
#include <istream>

class integer
{
    private:
        int i;
    public:
        integer();
        ~integer();
        integer(int);

        // friend integer& operator=(const integer& other);
        //
        integer& operator+=(const integer&);                      // compound addition
        friend integer operator+(const integer&, const integer&); // addition
        integer& operator-=(const integer&);                      // compound subtraction
        friend integer operator-(const integer&, const integer&); // subtraction

        integer& operator+=(int);
        friend integer operator+(const integer&, int);
        integer& operator-=(int);
        friend integer operator-(const integer&, int);

        integer operator++(int);                            
        integer& operator++();
        integer operator--(int);
        integer& operator--();

        friend bool operator==(const integer&, const integer&);
        friend bool operator!=(const integer&, const integer&);
        friend bool operator< (const integer&, const integer&);
        friend bool operator<=(const integer&, const integer&);
        friend bool operator> (const integer&, const integer&);
        friend bool operator>=(const integer&, const integer&);

        friend std::ostream& operator<<(std::ostream&, const integer&);
        friend std::istream& operator>>(std::istream&, integer&);
};
