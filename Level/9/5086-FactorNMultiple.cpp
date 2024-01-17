// 두 수 A, B
// A와 B의 관계 출력
// A가 B의 약수 => factor
// A가 B의 배수 => multiple
// 둘 다 아님 => neither

#include <iostream>

int main()
{
    int A, B;
    // 0 0 입력 받을 때까지 반복
    while (true)
    {
        std::cin >> A >> B;

        if (A + B == 0) break;

        // 둘 중 하나라도 0이면 neither
        if (A != 0 && B != 0)
        {
            // 배수 체크
            if (A % B == 0)
            {
                std::cout << "multiple" << std::endl;
                continue;
            }
            else if (A * (B / A) == B) // 약수 체크
            {
                std::cout << "factor" << std::endl;
                continue;
            }
        }

        // 둘 다 아님
        std::cout << "neither" << std::endl;
    }

    return 0;
}