#include <iostream>
using namespace std;

int main()
{
  // 테스트 케이스 개수
  int caseCount;
  cin >> caseCount;

  // 각 테스트 케이스의 시작 주소를 저장할 배열
  string** testCases = new string*[caseCount];
  // 각 테스트 케이스를 저장할 배열
  int repeatCount; // 반복 횟수
  string s; // 문자열
  for(int i = 0; i < caseCount; i++)
  {   
    cin >> repeatCount;  
    cin >> s;

    // 반복 횟수 * 문자열의 크기 만큼의 배열을 만듦
    testCases[i] = new string[repeatCount * s.size() + 1];

    for(int j = 0; j < repeatCount * s.size(); j += repeatCount)
    {
      // 반복 횟수만큼 문자 적기
      for(int k = 0; k < repeatCount; k++)
      {
        testCases[i][j+k] = s[j / repeatCount];
        cout << testCases[i][j+k]; // 출력
      }
    }
    cout << endl;
  }

  for(int i = 0; i < caseCount; i++)
  {
    delete[] testCases[i];
  }
  delete[] testCases;
  return 0;
}