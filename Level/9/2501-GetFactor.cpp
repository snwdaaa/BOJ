// p % q == 0 => q는 p의 약수
// N K => N의 약수 중 K번째로 작은 수

// N % I == 0인 I를 Deque에 저장 (I: 1 ~ N)
// 큐의 K번째 값 출력
// 큐의 크기가 K보다 작으면 0 출력

// 처음엔 큐에서 반복문 돌려서 K - 1개 만큼 Pop 하고 Front로 출력하려고 했는데
// 덱 써서 첨자 연산자로 접근하면 O(1)

#include <iostream>
#include <deque>

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::deque<int> factors; // N의 약수
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            factors.push_back(i);
        }
    }

    if (factors.size() < K)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << factors[K - 1];
    }

    return 0;
}