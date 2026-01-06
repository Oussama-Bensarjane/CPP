#include <iostream>
#include <iomanip>  // required for std::setw

int main() {
    std::string s = "Hello";
    std::string s1 = "";

    std::cout << s.length() << std::endl;
    if (s.empty())
        std::cout << "s: True" << std::endl;
    else
        std::cout << "s: False" << std::endl;

    if (s1.empty())
        std::cout << "s1: True" << std::endl;
    else
        std::cout << "s1: False" << std::endl;

    std::cout << s.substr(0, 4) << std::endl;
    std::cout << s + " Si ouss" << std::endl;
    return 0;
}
