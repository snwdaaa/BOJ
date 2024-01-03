#include <iostream>
#include <string>
using namespace std;

int main()
{
  // 1 ~ 0 사이의 다이얼을 돌리는데 필요한 시간
  int secondPerDial[10]= {
    0, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  };
  // 상근이 할머니가 외운 문자열
  string memorizedStr;
  // 전화를 거는데 필요한 최소 시간
  int minTime = 0;

  cin >> memorizedStr; // 문자열 입력

  // 문자 확인 후 시간 구하기
  for(int i = 0; i < memorizedStr.size(); i++)
  {
    if('A' <= memorizedStr[i] && memorizedStr[i] <= 'C')
      minTime += secondPerDial[2];
    else if('D' <= memorizedStr[i] && memorizedStr[i] <= 'F')
      minTime += secondPerDial[3];
    else if('G' <= memorizedStr[i] && memorizedStr[i] <= 'I')
      minTime += secondPerDial[4];
    else if('J' <= memorizedStr[i] && memorizedStr[i] <= 'L')
      minTime += secondPerDial[5];
    else if('M' <= memorizedStr[i] && memorizedStr[i] <= 'O')
      minTime += secondPerDial[6];
    else if('P' <= memorizedStr[i] && memorizedStr[i] <= 'S')
      minTime += secondPerDial[7];
    else if('T' <= memorizedStr[i] && memorizedStr[i] <= 'V')
      minTime += secondPerDial[8];
    else if('W' <= memorizedStr[i] && memorizedStr[i] <= 'Z')
      minTime += secondPerDial[9];
  }

  cout << minTime << endl;

  return 0;
}