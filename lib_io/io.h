#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

const auto EEOF = std::string("EOF Reached");

template<typename T>
T read()
{
    T n;
    std::cin >> n;
    if (std::cin.eof()) {
        throw std::invalid_argument("read(): " + EEOF);
    }
    return n;
}

template<typename T>
std::vector<T> read_vector(const unsigned int how_many)
{
    std::vector<T> ret;
    for (unsigned int i = 0; i < how_many; i++) {
        ret.push_back(read<T>());
        if (std::cin.eof()) {
            throw std::invalid_argument("read_vector(): " + EEOF);
        }
    }
    return ret;
}

template<typename T>
std::string vector_tostr(std::vector<T> &v)
{
    if (v.empty()) {
        return std::string("[]");
    }

    std::ostringstream vts;
    vts << "[";
    std::copy(v.begin(), v.end() - 1, std::ostream_iterator<T>(vts, ", "));
    vts << v.back();
    vts << "]";
    return vts.str();
}
