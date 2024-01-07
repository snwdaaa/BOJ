// 1 ~ N 바구니에 각 바구니 번호를 가진 공이 있음
// I번 바구니와 J번 바구니 M번 스왑
// 마지막에 모든 바구니 출력

#include <iostream>

int main()
{
    unsigned int M, N, i, j;
    std::cin >> N >> M;

    // 바구니 초기화
    unsigned int* arr = new unsigned int[N];
    for (int a = 1; a <= N; a++)
    {
        arr[a - 1] = a;
    }

    // 스왑
    for (int a = 0; a < M; a++)
    {
        std::cin >> i >> j;
        std::swap(arr[i - 1], arr[j - 1]);
    }

    // 출력
    for (int a = 0; a < N; a++)
    {
        std::cout << arr[a] << " ";
    }

    delete arr;
    return 0;
}