#include <string>
#include <sstream>

namespace cont
{
    template<class InputIt>
    std::string
    linear_tostr(InputIt first, InputIt last)
    {
        if (first == last) {
            return "[]";
        }
        auto it = first;
        std::stringstream ss;
        ss << "[" << *it;
        for ((void)++it; it != last; (void)++it) {
            ss << ", " << *it;
        }
        ss << "]";
        return ss.str();
    }

    template<class InputIt>
    std::string
    map_tostr(InputIt first, InputIt last)
    {

    }
}
