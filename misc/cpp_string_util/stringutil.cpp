#include "./stringutil.h"
#include <algorithm>
#include <unordered_set>

namespace str
{
    const std::string ascii_lowercase("abcdefghijklmnopqrstuvwxyz");
    const std::string ascii_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const std::string ascii_letters(ascii_lowercase + ascii_uppercase);
    const std::string digits("0123456789");
    const std::string hexdigits("0123456789abcdef");
    const std::string ifs(" \t\n");

    std::string
    tolower(const std::string& s)
    {
        std::string ret;
        std::transform(s.begin(), s.end(), std::back_inserter(ret), ::tolower);
        return ret;
    }

    std::string
    toupper(const std::string s)
    {
        std::string ret;
        std::transform(s.begin(), s.end(), std::back_inserter(ret), ::toupper);
        return ret;
    }

    // IsNotAllowedFn is a function(char) -> bool that returns true for a given
    // set of characters if it is not allowed.
    template<class IsNotAllowedFn>
    std::string
    _trim_with_function(const std::string& s, IsNotAllowedFn not_allowed)
    {
        size_t front = 0;
        size_t back = s.length() - 1;

        while (front < s.length() && not_allowed(s[front])) {
            front++;
        }

        while (back >= 0 && not_allowed(s[back])) {
            back--;
        }

        return s.substr(front, back - front + 1);
    }

    std::string
    trim(const std::string& s)
    {
        auto not_is_alnum = [](char c) {
            return !isalnum(c);
        };
        return _trim_with_function(s, not_is_alnum);
    }

    std::string
    trim(const std::string& s, const std::string& disallowed_charset)
    {
        return _trim_with_function(s, [disallowed_charset](char c) {
            std::unordered_set<char> disallowed(
                disallowed_charset.begin(),
                disallowed_charset.end()
            );
            return disallowed_charset.find(c) != std::string::npos;
        });
    }
};
