// 세 변의 길이
// 모두 같으면 Equilateral
// 두 개만 같으면 Isosceles
// 세 개 모두 다르면 Scalene

// 삼각형의 조건을 만족하지 못하면 Invalid
// 삼각형은 항상 가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 더 길다

#include <iostream>

const bool IsValidTriangle(int edges[])
{
    int longestEdgeIdx = -1;
    int longestEdgeLength = -1;
    for (int i = 0; i <= 2; i++)
    {
        if (longestEdgeLength < edges[i])
        {
            longestEdgeIdx = i;
            longestEdgeLength = edges[i];
        }
    }

    int lengthSum = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != longestEdgeIdx)
        {
            lengthSum += edges[i];
        }
    }

    if (longestEdgeLength >= lengthSum) // longestEdge를 제외한 두 변의 합이 longestEdge보다 작으면 삼각형 X
    {
        return false;
    }

    return true;
}

int main()
{
    int edges[3];

    while (true)
    {
        std::cin >> edges[0] >> edges[1] >> edges[2];

        if (edges[0] == 0 && edges[1] == 0 && edges[2] == 0) break;

        if (IsValidTriangle(edges))
        {
            if (edges[0] == edges[1] && edges[0] == edges[2] && edges[1] == edges[2]) // 세 변이 길이가 모두 같은 경우
            {
                std::cout << "Equilateral";
            }
            else if (edges[0] != edges[1] && edges[0] != edges[2] && edges[1] != edges[2]) // 세 변의 길이가 모두 다른 경우
            {
                std::cout << "Scalene";
            }
            else // 두 변의 길이만 같은 경우
            {
                std::cout << "Isosceles";
            }
        }
        else
        {
            std::cout << "Invalid";
        }
        std::cout << std::endl;
    }

    return 0;
}