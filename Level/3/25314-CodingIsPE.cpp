#include <iostream>

int main()
{
    // long 하나 당 4바이트로 생각
    // N을 4로 나눈 몫 만큼 long을 반복해서 입력한 후 뒤에 int를 붙임
    unsigned int N;
    std::cin >> N;

    for (int i = 0; i < N / 4; i++)
    {
        std::cout << "long ";
    }
    std::cout << "int";

    return 0;
}