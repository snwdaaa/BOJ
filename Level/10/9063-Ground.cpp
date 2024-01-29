#include <iostream>

struct Marble
{
    int x;
    int y;
};

int main()
{
    // 입력
    int N;
    std::cin >> N;
    if (N <= 1) // 구슬이 한 개 이하면 직사각형 X
    {
        std::cout << 0;
        return 0;
    }
    Marble* marbles = new Marble[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> marbles[i].x >> marbles[i].y;
    }

    // 대지 크기 계산
    // 가장 작은 & 가장 큰 x y를 구한 후
    // 직사각형의 가로 세로 => x_max - x_min, y_max - y_min
    int x_min = marbles[0].x;
    int x_max = marbles[0].x;
    int y_min = marbles[0].y;;
    int y_max = marbles[0].y;;
    for (int i = 0; i < N; i++)
    {
        if (marbles[i].x < x_min) x_min = marbles[i].x; // X 최소   
        if (marbles[i].y < y_min) y_min = marbles[i].y; // Y 최소
        if (marbles[i].x > x_max) x_max = marbles[i].x; // X 최소   
        if (marbles[i].y > y_max) y_max = marbles[i].y; // Y 최소
    }

    int xLength = x_max - x_min;
    int yLength = y_max - y_min;
    std::cout << xLength * yLength;

    return 0;
}