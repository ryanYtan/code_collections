#include <sstream>
#include <iostream>
#include <vector>

int main()
{
        std::string in;
        std::cin >> in;

        std::istringstream ss(in);
        std::string s;
        while (getline(ss, s, '-')) {
                std::cout << s.at(0);
        }
        std::cout << "\n";
}
