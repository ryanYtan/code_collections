#ifndef _STR_UTIL_LIB_INCLUDED_H
#define _STR_UTIL_LIB_INCLUDED_H
#include <string>
#include <sstream>
#include <ctype.h>

namespace str
{
    /**
     * Constants
     */
    extern const std::string ascii_lowercase;
    extern const std::string ascii_uppercase;
    extern const std::string ascii_letters;
    extern const std::string digits;
    extern const std::string hexdigits;
    extern const std::string ifs;

    /**
     * @brief Returns a lowercase version of the given string.
     *
     * @param s
     * @return std::string
     */
    std::string
    tolower(const std::string& s);

    /**
     * @brief Returns an uppercase version of the given string.
     *
     * @param s
     * @return std::string
     */
    std::string
    toupper(const std::string& s);

    /**
     * @brief Trims from both ends of the given string, characters for which
     * the isalnum() function from ctype.h returns false.
     *
     * @param s
     * @return std::string
     */
    std::string
    trim(const std::string &s);

    /**
     * @brief Trims from both ends of the given string, any characters that
     * in the given charset.
     *
     * @param s
     * @param disallowed_charset
     * @return std::string
     */
    std::string
    trim(const std::string &s, const std::string& disallowed_charset);

    /**
     * @brief Returns true if the string haystack contains the string needle
     *
     * @param haystack
     * @param needle
     * @return bool
     */
    bool
    contains(const std::string& haystack, const std::string& needle)
    {
        return haystack.find(needle) != std::string::npos;
    }

    /**
     * @brief Joins all string representations of the objects using the given
     * delimiter. All types given in InputIt must implement the << operator.
     *
     * @tparam InputIt
     * @param first
     * @param last
     * @param delim
     * @return std::string
     */
    template<class InputIt>
    std::string
    join(InputIt first, InputIt last, const std::string& delim)
    {
        if (first == last)
            return "";
        std::stringstream ss;
        ss << *first;
        for ((void)++first; first != last; (void)++first) {
            ss << delim << *first;
        }
        return ss.str();
    }


    /**
     * @brief Splits a std::string using the given delimiter.
     *
     * Adapted with minor modifications: https://stackoverflow.com/a/57346888/10966389
     *
     * @tparam StringOutputIt
     * @param result
     * @param s
     * @return StringOutputIt
     */
    template<class StringOutputIt>
    StringOutputIt
    split(StringOutputIt result, const std::string& s, const std::string& delim)
    {
        if (delim.empty()) {
            *result = s;
            return result;
        }

        if (s.empty()) {
            *result = "";
            return result;
        }

        std::string curr;

        for (char c : s) {
            curr += c;

            if (curr == delim) {
                *result = "";
                (void)++result;
                curr = "";
            }

            if (contains(curr, delim)) {
                size_t start = 0;
                size_t end = curr.length() - delim.length();
                std::string element = curr.substr(start, end - start);
                *result = element;
                (void)++result;
                curr = "";
            }
        }

        // get last element
        *result = curr;
        return result;
    }
};

#endif
