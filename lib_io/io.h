#ifndef CCOLLECTIONS_IO_H_INCLUDED
#define CCOLLECTIONS_IO_H_INCLUDED
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

const auto MESSAGE_EEOF = std::string("EOF Reached");

template<class T>
T read()
{
    T n;
    std::cin >> n;
    return n;
}

template<class OutputIt>
void read_values(size_t how_many, OutputIt start)
{
    using ReadType = typename std::iterator_traits<OutputIt>::value_type;
    for (size_t i = 0; i < how_many; i++) {
        *start = read<ReadType>();
        (void)start++;
    }
}

template<class Container>
std::string tostr(const Container& con)
{
    if (con.empty()) {
        return "[]";
    }
    std::ostringstream ss;
    ss << "[" << con[0];
    for (size_t i = 1; i < con.size(); i++) {
        ss << ", " << con[i];
    }
    ss << "]";
    return ss.str();
}

#endif
