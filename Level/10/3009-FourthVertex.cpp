// 네 번째 점이 어떤 위치에 들어가야 할 지 파악해야 함

#include <iostream>

int main()
{
    int x1 = -1;
    int x2 = -1;
    int y1 = -1;
    int y2 = -1;

    int x1Cnt = 0;
    int x2Cnt = 0;
    int y1Cnt = 0;
    int y2Cnt = 0;

    std::cin >> x1 >> y1;
    x1Cnt++;
    y1Cnt++;

    for(int i = 0; i < 2; i++)
    {
        int tempX, tempY;
        std::cin >> tempX >> tempY;

        if (tempX == x1) x1Cnt++;
        else
        {
            x2Cnt++;
            x2 = tempX;
        }

        if (tempY == y1) y1Cnt++;
        else
        {
            y2Cnt++;
            y2 = tempY;
        }
    }

    if (x1Cnt < x2Cnt) std::cout << x1;
    else std::cout << x2;
    std::cout << " ";

    if (y1Cnt < y2Cnt) std::cout << y1;
    else std::cout << y2;

    return 0;
}