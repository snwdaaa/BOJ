#include <iostream>

int main()
{
    unsigned int N, M;
    std::cin >> N >> M;
    
    // 배열 할당 및 초기화
    unsigned int* arr = new unsigned int[N];
    for (int a = 0; a < N; a++)
    {
        arr[a] = a + 1;
    }

    //M번 바구니 뒤집기
    unsigned int i, j;
    for (int a = 0; a < M; a++)
    {
        std::cin >> i >> j;
        while (i < j)
        {
            std::swap(arr[i - 1], arr[j - 1]);
            i++;
            j--;
        }
    }

    for (int a = 0; a < N; a++)
    {
        std::cout << arr[a] << " ";
    }

    delete arr;
    return 0;
}