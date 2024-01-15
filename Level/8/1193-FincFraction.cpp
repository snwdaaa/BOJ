// 분수 찾기
// y / x 형태, 맨 왼쪽 위 1 / 1로 시작 (x=1, y=1)
// 지그재그로 이동했을 때 X번째 값 구하기

#include<iostream>

int main()
{
    int X;
    std::cin >> X;

    // 1이면 바로 종료
    if (X == 1)
    {
        std::cout << "1/1";
        return 0;
    }

    // 두 번째 (1 / 2) 부터 시작
    float x = 2.0f;
    float y = 1.0f;
    int moveCnt = 2;
    int iterCnt; // 대각 이동 반복 횟수
    while (moveCnt != X)
    {
        // 왼쪽 아래로 이동
        iterCnt = (int)x - 1;
        for (int i = 0; i < iterCnt && moveCnt != X; i++)
        {
            y += 1.0f;
            x -= 1.0f;
            moveCnt++;
        }
        if (moveCnt == X) break;

        // 아래로 한 칸 이동
        y += 1.0f;
        moveCnt++;
        if (moveCnt == X) break;      

        // 오른쪽 위로 이동
        iterCnt = (int)y - 1;
        for (int i = 0; i < iterCnt && moveCnt != X; i++)
        {
            y -= 1.0f;
            x += 1.0f;
            moveCnt++;
        }
        if (moveCnt == X) break;

        // 오른쪽으로 한 칸 이동
        x += 1.0f;
        moveCnt++;
    }

    std::cout << y << "/" << x;

    return 0;
}