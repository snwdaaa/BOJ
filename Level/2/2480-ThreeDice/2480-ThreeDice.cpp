// 1~6 눈 있는 주사위 세 개
// 같은 눈 3개 => 10000 + (같은 눈) * 1000
// 같은 눈 2개 => 1000 + (같은 눈) * 100
// 모두 다른 눈 => (그 중 가장 큰 눈) * 100
// 상금 계산 후 출력

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> dice(3);
    for(int i = 0; i < 3; ++i) cin >> dice[i];

    // 생각해야 할 것
    // 1. 어떻게 같은 눈의 개수를 셀 것인가?
    //      크기가 6인 배열을 만든 후, 인덱스+1인 수가 나오면 요소 +1
    //      나중에 for문 돌면서 값이 3인 인덱스, 2인 인덱스 검사
    //      3, 2인 인덱스 없으면 값이 1인 인덱스 중 가장 큰 인덱스 가져오기
    vector<int> diceCount(6);   // 각 인덱스+1에 맞는 눈이 나온 횟수를 저장할 배열
    bool isAllDiceIsDiff = true;   // 모든 주사위의 눈이 서로 다른가?
    for(int i = 0; i < 3; ++i) diceCount[dice[i]-1]++;  // 주사위 눈에 해당하는 요소를 +1
    for(int i = 0; i < 6; ++i)  // 같은 눈 개수 3, 2개인 경우 검사
    {
        if(diceCount[i] == 3)
        {
            cout << 10000 + (i+1) * 1000 << endl;
            isAllDiceIsDiff = false;
            break;
        }
        else if(diceCount[i] == 2)
        {
            cout << 1000 + (i+1) * 100 << endl;
            isAllDiceIsDiff = false;
            break;
        }
    }

    if (isAllDiceIsDiff)    // 모든 주사위의 눈이 서로 다른 경우
    {
        int biggest; // 가장 큰 눈
        // 가장 큰 눈 찾기
        for(int i = 0; i < 6; ++i)
        {
            if (diceCount[i] == 1) biggest = i + 1; // 제일 마지막에 biggest가 되는 눈이 가장 큰 눈임
        }
        cout << biggest * 100 << endl;
    }

    return 0;
}