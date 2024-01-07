#include <iostream>
using namespace std;

int main()
{
  unsigned int testCount;
  cin >> testCount;

  // 점수 입력
  unsigned int* testScore = new unsigned int[testCount];
  for(int i = 0; i < testCount; i++)
  {
    cin >> testScore[i];
  }

  // 최댓값 찾기
  unsigned int maxScore = testScore[0];
  for(int i = 0; i < testCount; i++)
  {
    if(testScore[i] > maxScore)
    {
      maxScore = testScore[i];
    }
  }

  // 새로운 점수를 저장할 배열 & 평균 계산
  double* newScore = new double[testCount];
  double sum = 0;
  double newAverage;
  for(int i = 0; i < testCount; i++)
  {
    newScore[i] = ((double)testScore[i] / maxScore) * 100.0f;
    sum += newScore[i];
  }

  newAverage = sum / testCount;

  cout << newAverage << endl;

  delete[] testScore;
  return 0;
}