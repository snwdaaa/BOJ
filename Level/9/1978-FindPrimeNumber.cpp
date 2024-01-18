// 주어진 N개의 수 중 소수 몇 개인지 찾기

#include <iostream>

int main()
{
    int N;
    int primeCount = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K;
        std::cin >> K;

        // 약수 구해서 개수 2개면 소수
        int factorCount = 0;
        for (int j = 1; j <= K; j++)
        {
            if (K % j == 0) factorCount++;
        }

        if (factorCount == 2) primeCount++;
    }

    std::cout << primeCount;

    return 0;
}