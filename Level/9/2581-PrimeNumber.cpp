#include <iostream>
#include <queue>

int main()
{
    // M과 N 입력
    int M, N;
    std::cin >> M >> N;

    // M ~ N 사이의 자연수 중 소수 찾아서 큐에 저장
    std::queue<int> primeNums;
    for (int i = M; i <= N; i++)
    {
        // i가 소수인 지 판별
        int factorCount = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0) factorCount++;
        }
        if (factorCount == 2)
        {
            primeNums.push(i);
        }
    }

    // M ~ N 사이에 소수가 없는 경우 -1 출력 후 종료
    if (primeNums.empty())
    {
        std::cout << -1;
        return 0;
    }

    // 최솟값 찾기
    int min = primeNums.front();

    // 소수합 계산
    int sum = 0;
    while (!primeNums.empty())
    {
        sum += primeNums.front();
        primeNums.pop();
    }

    // 출력
    std::cout << sum << std::endl;
    std::cout << min << std::endl;
}