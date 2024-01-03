// 킹, 퀸, 룩, 비숍, 나이트, 폰의 모자란 개수 구하기
// 기본적으로 킹(1), 퀸(1), 룩(2), 비숍(2), 나이트(2), 폰(8)

#include <iostream>

int main(void)
{
    const int validChessPieces[6] = {1, 1, 2, 2, 2, 8}; // 올바른 피스의 수
    int chessPieces[6]; // 입력된 피스의 수
    for(int i = 0; i < 6; i++)
    {
        std::cin >> chessPieces[i];
        std::cout << validChessPieces[i] - chessPieces[i] << " ";
    }

    return 0;
}