// 정삼각형과 직각 삼각형 두 경우를 생각

// a, b, c가 막대의 최대 길이고, abc부터 시작해서 줄여나가면서 만들 수 있는 둘레가 가장 큰 삼각형을 만드는 것
// 그럼 삼각형의 정의 안에서 세 변의 길이를 최대로 하면 됨

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
    std::cin >> edges[0] >> edges[1] >> edges[2];

    // 삼각형이 만들어지면 바로 세 변의 길이를 더하고
    // 만들어지지 않으면 가장 큰 변의 길이를 조금씩 줄이면서 삼각형이 될 때까지 반복
    if (!IsValidTriangle(edges))
    {
        // 가장 긴 변의 인덱스 찾기
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

        while (!IsValidTriangle(edges))
        {
            edges[longestEdgeIdx] -= 1;
        }      
    }
    std::cout << edges[0] + edges[1] + edges[2];

    return 0;
}