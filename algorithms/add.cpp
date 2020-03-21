#include <iostream>

int _chartoi(const char c)
{
    constexpr auto offset = 48;
    return (int)c - offset;
}

int _has_carry(const int i)
{
    return i >= 10;
}

int _prepend_digit(std::string &result, int sum)
{
    result = std::to_string(sum % 10) + result;
    return _has_carry(sum);
}

void _prepend_init(std::string &result, const std::string &f,
                   const std::string &s, int &i, int &j, int &carry)
{
    while (i >= 0 && j >= 0) {
        int sum = _chartoi(f.at(i)) + _chartoi(s.at(j)) + carry;
        carry = _prepend_digit(result, sum);
        i--;
        j--;
    }
}

void _prepend_remaining(std::string &result, const std::string &s,
                       int &index, int &carry)
{
    while (index >= 0) {
        int sum = _chartoi(s.at(index)) + carry;
        carry = _prepend_digit(result, sum);
        index--;
    }
}

void _prepend_carry(std::string &result, int &carry)
{
    if (carry)
        result = std::to_string(carry) + result;
}

std::string add(const std::string f, const std::string s)
{
    std::string result;
    int i = f.length() - 1;
    int j = s.length() - 1;
    int carry = 0;

    _prepend_init(result, f, s, i, j, carry);
    _prepend_remaining(result, f, i, carry);
    _prepend_remaining(result, s, j, carry);
    _prepend_carry(result, carry);

    return result;
}

int main(void)
{
    std::string first;
    std::string second;
    std::cin >> first >> second;
    std::cout << add(first, second) << "\n";
}
