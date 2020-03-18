#include <iostream>
#include <vector>

"""
Prints all possible subsets of a string
"""
void all_substr(std::vector<std::string> &output, const std::string &s,
                std::string sub_str, size_t index)
{
    if (index == s.length()) {
        if (sub_str.length() > 0) { // avoid empty str
            output.push_back(sub_str);
        }
    } else {
        all_substr(output, s, sub_str, index + 1);
        all_substr(output, s, sub_str + s.at(index), index + 1);
    }
}

int main()
{
    std::string input;
    std::cin >> input;
    std::vector<std::string> substrings;
    all_substr(substrings, input, std::string(""), 0);

    for (size_t i = 0; i < substrings.size(); i++) {
        std::cout << substrings[i] << "\n";
    }
}
