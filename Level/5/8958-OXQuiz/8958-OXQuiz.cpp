#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int caseCount;
  cin >> caseCount;

  string* testCases = new string[caseCount];
  for(int i = 0; i < caseCount; i++)
  {
    cin >> testCases[i];
  }

  bool isContinuousCorrect; // 연속 정답 여부
  unsigned int* result = new unsigned int[caseCount]; // 점수 배열
  unsigned int score;

  for(int i = 0; i < caseCount; i++)
  {
    score = 2;
    isContinuousCorrect = false;
    for(int j = 0; j < testCases[i].size(); j++)
    { 
      // 정답일 때
      if(testCases[i][j] == 'O')
      {
        // 연속된 정답일 때
        if(isContinuousCorrect == true)
        {
          result[i] += score;
          score++;
        }
        else if(isContinuousCorrect == false)
        {
          isContinuousCorrect = true;
          result[i]++;
        }
      }
      else
      {
        isContinuousCorrect = false;
        score = 2;
      }
    }
  }

  // 결과 출력
  for(int i = 0; i < caseCount; i++)
  {
    cout << result[i] << endl;
  }

  delete[] testCases;
  delete[] result;
  return 0;
}