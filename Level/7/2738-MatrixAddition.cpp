// N * M 크기 두 행렬 A와 B 덧셈

#include <iostream>

int main()
{
    int N, M;
    std::cin >> N >> M;

    // 2차원 동적 배열 생성
    int** matrixA = new int*[N];
    int** matrixB = new int*[N];
    for (int i = 0; i < N; i++)
    {
        matrixA[i] = new int[M];
        matrixB[i] = new int[M];
    }

    // MatrixA 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> matrixA[i][j];
        }
    }
    // MatrixB 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> matrixB[i][j];
        }
    }

    // Matrix 덧셈 & 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << matrixA[i][j] + matrixB[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 메모리 해제
    for (int i = 0; i < N; i++)
    {
        delete matrixA[i];
        delete matrixB[i];
    }
    delete matrixA;
    delete matrixB;

    return 0;
}