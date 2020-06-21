/**
 * Statistics methods on linear containers such as list or vector.
 */
#include <algorithm>
#include <iterator>
#include <unordered_map>

namespace stats
{
    constexpr auto _ERR_EMPTY_SEQUENCE = "sequence passed is empty";

    template<class T>
    auto square(T x) noexcept -> T
    {
        return x * x;
    }

    template<class T>
    auto cube(T x) noexcept -> T
    {
        return x * x * x;
    }

    template<class InputIt>
    static
    void _check_empty_sequence(InputIt lhs, InputIt rhs)
    {
        if (lhs == rhs) {
            throw std::invalid_argument(_ERR_EMPTY_SEQUENCE);
        }
    }

    template<class InputIt>
    auto max(InputIt first, InputIt last)
            -> typename std::iterator_traits<InputIt>::value_type
    {
        using T = typename std::iterator_traits<InputIt>::value_type;
        _check_empty_sequence(first, last);

        T max = *first;
        for (auto it = first; it != last; ++it) {
            if (max < *it) {
                max = *it;
            }
        }
        return max;
    }

    template<class InputIt>
    auto min(InputIt first, InputIt last)
            -> typename std::iterator_traits<InputIt>::value_type
    {
        using T = typename std::iterator_traits<InputIt>::value_type;
        _check_empty_sequence(first, last);

        T min = *first;
        for (auto it = first; it != last; ++it) {
            if (*it < min) {
                min = *it;
            }
        }
        return min;
    }

    template<class InputIt>
    auto mode(InputIt first, InputIt last)
            -> typename std::iterator_traits<InputIt>::value_type
    {
        using T = typename std::iterator_traits<InputIt>::value_type;
        _check_empty_sequence(first, last);

        std::unordered_map<T, size_t> counter;

        for (auto it = first; it != last; ++it) {
            if (counter.find(*it) == counter.end()) {
                counter[*it] = 1;
            } else {
                counter[*it] += 1;
            }
        }

        T key_of_max = counter.begin()->first;
        size_t max = counter[key_of_max];
        for (const auto& [key, value] : counter) {
            if (max < value) {
                max = value;
                key_of_max = key;
            }
        }

        return key_of_max;
    }

    template<class InputIt>
    auto median(InputIt first, InputIt last)
            -> typename std::iterator_traits<InputIt>::value_type
    {
        using T = typename std::iterator_traits<InputIt>::value_type;
        _check_empty_sequence(first, last);

        std::vector<T> copy;
        for (auto it = first; it != last; ++it) {
            copy.push_back(*it);
        }
        std::sort(copy.begin(), copy.end());

        if (copy.size() % 2 == 0) {
            size_t lef = copy.size() / 2 - 1;
            size_t rgt = copy.size() / 2;
            return (copy[lef] + copy[rgt]) / 2;
        } else {
            return copy[copy.size() / 2];
        }
    }

    template<class InputIt>
    auto mean(InputIt first, InputIt last) -> double
    {
        _check_empty_sequence(first, last);

        double mean = 0;
        size_t t = 1;
        for (auto it = first; it != last; ++it) {
            mean += (static_cast<double>(*it) - mean) / t;
            t++;
        }
        return mean;
    }

    template<class InputIt>
    auto variance(InputIt first, InputIt last) -> double
    {
        _check_empty_sequence(first, last);

        size_t length = 0;

        double m = 0;
        double s = 0;
        double old_m;
        for (auto it = first; it != last; ++it) {
            double x = static_cast<double>(*it);
            old_m = m;
            m = m + ((x - m) / (length + 1));
            s = s + ((x - m) * (x - old_m));
            length++;
        }
        return s / (length - 1);
    }

    template<class InputIt>
    auto stdev(InputIt first, InputIt last) -> double
    {
        return sqrt(variance(first, last));
    }
}
