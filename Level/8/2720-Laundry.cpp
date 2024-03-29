// 리암 갤러거는 계산엔 재능 없는 듯

// 거스름돈의 액수 입력, 쿼터(0.25), 다임(0.10), 니켈(0.05), 페니(0.01)의 개수를 구하기
// 거스름돈은 항상 $5.00 이하, 동전 개수 최소
// ex) $1.24 = 4쿼터, 2다임, 0니켈, 4페니
// 1달러 = 100센트
// 0.25달러 = 25센트
// 0.10달러 = 10센트
// 0.05달러 = 5센트
// 0.01달러 = 1센트

#include <iostream>

int main()
{
    int T, C; // 테스트 케이스, 거스름돈(센트)
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> C;

        // 거스름돈 계산
        int q, d, n, p; // 쿼터, 다임, 니켈, 페니
        // 쿼터
        q = C / 25;
        C -= q * 25;
        // 다임
        d = C / 10;
        C -= d * 10; 
        // 니켈
        n = C / 5;
        C -= n * 5;
        // 페니
        p = C;

        // 거스름돈 출력
        std::cout << q << " " << d << " " << n << " " << p << std::endl;
    }

    return 0;
}