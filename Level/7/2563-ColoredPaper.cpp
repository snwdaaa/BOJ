#include <iostream>

int main()
{
    bool canvas[100][100] = {0, }; // 색종이가 붙어있으면 1, 아니면 0

    int paperCnt; // 색종이의 수
    std::cin >> paperCnt;

    for (int i = 0; i < paperCnt; i++)
    {
        // 색종이 위치 입력
        int paperX, paperY; // 색종이 왼쪽 아래 정점의 위치 좌표
        std::cin >> paperX >> paperY;

        // 색종이 붙이기
        // 원점이 도화지의 왼쪽 아래 -> canvas[99][0]이 원점인 것 주의
        // 색종이 왼쪽 아래 (paperX, paperY) => 도화지 (99 - (paperY-1), paperX + 1)
        for (int j = 0; j < 10; j++) // 가로로 한 줄씩 채우면서 올라감
        {
            for (int k = 0; k < 10; k++) //
            {
                canvas[(99 - (paperY - 1)) - j][(paperX + 1) + k] = 1; 
            }
        }
    }

    // 색종이 넓이 구하기
    int paperArea = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if (canvas[i][j] == 1)
            {
                paperArea++;
            }
        }
    }

    std::cout << paperArea; // 넓이 출력

    return 0;
}