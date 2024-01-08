// 별 찍기 7
//4     * 1
//3    *** 3
//2   ***** 5 
//1  ******* 7
//0 ********* 9
//1  ******* 7
//2   ***** 5
//3    *** 3
//4     * 1

#include <iostream>

int main()
{
    unsigned int N;
    std::cin >> N;

    // 윗 부분
    for (int i = 0; i < N; i++)
    {
        // 공백
        for (int j = 0; j < N - i - 1; j++)
        {
            std::cout << " ";
        }

        // 별
        for (int j = 0; j < 2*i + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // 아랫 부분
    for (int i = N - 1; i > 0; i--)
    {
        // 공백
        for (int j = N - i - 1; j >= 0; j--)
        {
            std::cout << " ";
        }

        // 별
        for (int j = 2*i - 1; j > 0; j--)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}