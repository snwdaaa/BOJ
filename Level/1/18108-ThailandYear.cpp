// 불기 연도 -> 서기 연도
#include <iostream>

int main(void)
{
    unsigned short thaiYear, korYear;
    std::cin >> thaiYear;
    korYear = thaiYear - 543;
    std::cout << korYear;

    return 0;
}