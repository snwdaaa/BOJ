// 항상 포함되는 넓이

#include <iostream>

int main()
{
    // int N;
    // std::cin >> N;

    // if (N == 1)
    // {
    //     std::cout << 4;
    // }
    // else if (N == 2)
    // {
    //     std::cout << 8;
    // }
    // else if (N >= 3)
    // {
    //     int tempSum = 0;
    //     // 전체 둘레
    //     for (int i = 3; i <= N; i++)
    //     {
    //         tempSum += N;
    //     }
    //     int entirePeri = 4 * (3 + tempSum);

    //     // 중복되는 둘레
    //     tempSum = 0;
    //     for (int i = 2; i <= N-1; i++)
    //     {
    //         tempSum += N;
    //     }
    //     int overlappedPeri = 3 * (1 + tempSum);

    //     std::cout << entirePeri - overlappedPeri;
    // }

    unsigned int N;
    std::cin >> N;

    std::cout << 4*N;

    return 0;
}