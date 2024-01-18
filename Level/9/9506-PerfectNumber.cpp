// 완전수
// 자기 자신 = 자신을 제외한 모든 약수를 더한 결과

#include <iostream>
#include <queue>

int main()
{
    while (true)
    {
        int N;
        std::cin >> N;

        if (N == -1) break;

        int factorSum = 0;
        std::queue<int> factors; // N의 약수
        for (int i = 1; i < N; i++) // 자신을 제외한 모든 약수를 큐에 추가
        {
            if (N % i == 0)
            {
                factors.push(i);
                factorSum += i;
            }
        }

        if (factorSum == N) // 모든 약수의 합 == N이면 완전수
        {
            std::cout << N << " = ";
            while (!factors.empty())
            {
                std::cout << factors.front() << ((factors.size() == 1) ? "" : " + ");
                factors.pop();
            }
        }
        else
        {
            std::cout << N << " is NOT perfect.";
        }
        std::cout << std::endl;
    }

    return 0;
}