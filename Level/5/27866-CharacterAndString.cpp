#include <iostream>

int main()
{
    std::string str;
    unsigned int i;

    std::cin >> str >> i;
    std::cout << str.at(i - 1);

    return 0;
}