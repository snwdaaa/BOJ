// B진법 수 N -> 10진법
// B: 2 ~ 36
// ex) ZZZZZ 36 (36진법 수 ZZZZZ) 입력

#include <iostream>
#include <cmath>
#include <queue>

int main()
{
    int N; // 수
    int B; // 진법
    std::cin >> N >> B;

    // 자리수 찾기
    int maxExp = 0;
    for(int i = 0; N % (int)std::pow(B, i) != N; i++)
    {
        maxExp++;
    }
    maxExp--; // for문 안에서는 최대 자리수보다 하나 크게 나옴

    std::queue<char> chQueue;
    int nTemp = N;   
    for (int i = maxExp; i >= 0; i--) // B^i로 나눈 몫을 큐에 저장한 후, B^i로 나눈 나머지에 대해 i 감소하면서 반복
    {
        // N을 B^i로 나눈 몫을 문자로 변경 -> 숫자, 문자 구별
        char iToC; 
        int modTemp = nTemp / (int)std::pow(B, i);
        if (modTemp >= 0 && modTemp <= 9) // 숫자
        {
            iToC = (char)(modTemp + 48);
        }
        else // 문자
        {
            iToC = (char)(modTemp + 55);
        }
        chQueue.push(iToC);
      
        nTemp -= modTemp * (int)std::pow(B, i); // 나눈 몫의 나머지에 대해 다시 연산
    }
  
    while (!chQueue.empty()) // 큐 출력
    {
        std::cout << chQueue.front();
        chQueue.pop();
    }

    return 0;
}