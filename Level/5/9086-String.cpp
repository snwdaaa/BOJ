// 문자열의 첫 글자와 마지막 글자를 출력

#include <iostream>
#include <string>

int main()
{
    unsigned int T;
    std::cin >> T;

    std::string str;

    // 문자열 입력 -> 문자열 첫 글자, 마지막 글자 출력
    for (int i = 0; i < T; i++)
    {
        std::cin >> str;
        std::cout << str.at(0) << str.at(str.length() - 1) << std::endl;
    }
    
    return 0;
}