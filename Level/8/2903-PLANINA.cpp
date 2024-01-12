// 정사각형 이루는 점 4개
// 1. 각 변의 중앙에 점을 하나 추가
// 2. 정사각형 중심에 점을 하나 추가
// => 4개의 정사각형 새로 생김

// 중복되는 점은 하나만 저장
// N번 후 점 몇 개를 저장해야 하는지?

#include <iostream>
#include <cmath>

int main()
{
    int N, a;
    std::cin >> N;

    a = 2;
    for (int i = 1; i <= N; i++)
    {
        a += (int)std::pow(2, i-1);
    }

    std::cout << (int)std::pow(a, 2);

    return 0;
}