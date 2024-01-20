#include <iostream>

int main()
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    int xDist, yDist;

    xDist = (x < (w - x)) ? x : w - x;
    yDist = (y < (h - y)) ? y : h - y;

    std::cout << int((xDist > yDist) ? yDist : xDist);

    return 0;
}