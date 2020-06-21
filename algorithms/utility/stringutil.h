#include <sstream>

template<typename InputIt>
std::string join(InputIt start, InputIt last, const std::string& delim = " ")
{
    if (start == last) {
        return "";
    }

    std::stringstream ss;
    ss << *start;
    (void)++start;
    for (; start != last; (void)++start) {
        ss << delim << *start;
    }
    return ss.str();
}

// Adapted w/ minor modifications: https://stackoverflow.com/a/57346888/10966389
template<typename OutputIt>
OutputIt
split(OutputIt result, const std::string& s, const std::string& delim = " ")
{
    if (s.empty()) {
        *result = "";
        return result;
    }

    size_t found = s.find(delim);
    size_t start_index = 0;

    while (found != std::string::npos) {
        std::string temp(s.begin() + start_index, s.begin() + found);

        *result = temp;
        (void)++result;

        start_index = found + delim.size();
        found = s.find(delim, start_index);
    }

    *result = std::string(s.begin() + start_index, s.end());
    return result;
}

static
bool _is_trimmable(char c)
{
    return !std::isalnum(c);
}

std::string trim(const std::string& s)
{
    size_t front = 0;
    size_t back = s.length() - 1;

    while (front < s.length() && _is_trimmable(s[front])) {
        front++;
    }

    while (back >= 0 && _is_trimmable(s[back])) {
        back--;
    }

    return s.substr(front, back - front + 1);
}
