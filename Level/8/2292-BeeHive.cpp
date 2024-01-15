// 1번 방부터 시작해서 N번 방까지 최소 개수의 방을 지나감
// 지나가는 방의 개수?

#include <iostream>

int main(void)
{
    int N;
    std::cin >> N;

    // 1이면 바로 종료
    if (N == 1)
    {
        std::cout << 1;
        return 0;
    }

    int a = 1;
    int moveCnt = 1; // 이동 횟수
    int b;
    int c;
    while (true)
    {
        b = a + 1;
        c = a + 6 * moveCnt;    
        a = c;
        moveCnt++;
        if (b <= N && c >= N) break;    
    }

    std::cout << moveCnt;

    return 0;
}