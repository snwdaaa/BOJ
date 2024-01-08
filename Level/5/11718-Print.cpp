// 입력 받은 그대로 출력

#include <iostream>
#include <string>

int main()
{
    std::string str;

    while (true)
    {
        if (std::cin.eof())
        {
            break;
        }          

        std::getline(std::cin, str);
        std::cout << str << std::endl;
    }

    return 0;
}