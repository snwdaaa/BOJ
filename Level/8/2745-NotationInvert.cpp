// 10진법 수 N -> B 진법
// B: 2 ~ 36, N: 자연수, N <= 10억
// ex) 60466175 36 (10진법 수 60466175) 입력

#include <iostream>
#include <cmath>

int main()
{
    std::string N; // 수
    int B; // 진법
    std::cin >> N >> B;

    // 먼저 해당 자리수에 있는 문자를 10진수로 결정한 후
    // 자리수에 맞게 B^0, B^1, .. 을 곱해줌
    int decimalResult = 0; // 10진수 값 결과
    for (int i = N.length() - 1; i >= 0; i--)
    {
        if (N.at(i) >= 65 && N.at(i) <= 90) // 문자
        {
            decimalResult += (N.at(i) - 55) * std::pow(B, N.length() - 1 - i);
        }
        else // 숫자
        {
            decimalResult += (N.at(i) - 48) * std::pow(B, N.length() - 1 - i);
        }      
    }

    std::cout << decimalResult;

    return 0;
}