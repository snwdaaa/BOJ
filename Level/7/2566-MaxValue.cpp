// 9x9 행렬에서 최댓값 찾고 행, 열 출력
#include <iostream>

int main()
{
    int matrix[9][9] = {0, }; // 9x9 행렬. 0으로 초기화

    // 각 행 돌면서 그 행의 최댓값 가지고 나옴
    // 그 최댓값 가지고 다음 행 가서 또 비교
    // => 루프 끝나면 maxValue에 모든 행에서의 최댓값 저장
    int maxValue = -1; // 최댓값
    int maxValueIdx_row, maxValueIdx_column; // 최댓값의 행, 열 인덱스
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cin >> matrix[i][j];
            if (matrix[i][j] > maxValue)
            {
                maxValue = matrix[i][j];
                maxValueIdx_row = i;
                maxValueIdx_column = j;              
            }
        }
    }

    // 출력
    std::cout << maxValue << std::endl << maxValueIdx_row + 1 << " " << maxValueIdx_column + 1; // 출력 때 행, 열 1부터 시작하는 거 주의

    return 0;
}