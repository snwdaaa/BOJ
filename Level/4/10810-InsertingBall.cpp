// 바구니 N개, 1~N 적힌 공 N개, 바구니에는 공 하나만
// M번 공을 넣음, 공을 넣을 때마다 바구니 범위를 정하고, 범위 안의 모든 바구니에 같은 공을 넣음
// 만약 이미 바구니에 공이 있다면 새로 넣는 공으로 바꿈
// M번 공을 넣은 뒤 각 바구니에 어떤 공이 들어 있는지 출력

// 첫째 줄 => N, M
// 둘째 줄부터 공을 넣는 방법을 M번 출력
// 각 방법은 정수 i, j, k => i번 바구니 ~ j번 바구니에 모두 k번 번호가 적힌 공을 넣는 것

// 1번 바구니 ~ N번 바구니에 들어있는 공의 번호를 출력. 공이 없으면 0 출력

#include <iostream>

int main()
{
    unsigned int N, M;
    std::cin >> N >> M;

    unsigned int* arr = new unsigned int[N];   
    for (int a = 0; a < N; a++)
    {
        arr[a] = 0; // 배열 0으로 초기화
    }
    
    unsigned int i, j, k;
    for (int a = 0; a < M; a++)
    {
        std::cin >> i >> j >> k;
        for (int b = i - 1; b <= j - 1; b++)
        {
            arr[b] = k;
        }        
    }

    for (int a = 0; a < N; a++)
    {
        std::cout << arr[a] << " ";
    }
    delete arr;
    return 0;
}