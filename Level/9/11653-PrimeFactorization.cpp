#include <iostream>
#include <queue>

int main()
{
    int N;
    std::cin >> N;

    std::queue<int> primeFactors; // N의 약수 중 소수인 수
    // 1을 제외한 N의 약수 중 소수를 큐에 저장
    for (int i = 2; i <= N; i++)
    {
        // i가 N의 약수인 지 확인
        if (N % i == 0)
        {
            // i가 소수인지 확인
            int factorCount = 0;
            for (int j = 1; j <= i; j++)
            {      
                if (i % j == 0) factorCount++;
            }
            if (factorCount == 2) // 약수 i가 소수면 큐에 저장
            {
                primeFactors.push(i);
            }
        }
    }

    while (N != 1)
    {
        if (N % primeFactors.front() != 0) primeFactors.pop();
        std::cout << primeFactors.front() << std::endl;
        N = N / primeFactors.front();
    }

    return 0;
}