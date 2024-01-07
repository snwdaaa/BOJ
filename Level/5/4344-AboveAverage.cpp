#include <iostream>
using namespace std;

int main()
{
  // 테스트 케이스 개수
  unsigned int caseCount;
  cin >> caseCount;

  // 테스트 케이스 배열 생성
  unsigned int** testCases;
  testCases = new unsigned int*[caseCount];

  // 테스트 케이스 당 학생 수를 저장할 배열
  unsigned int* studentCount = new unsigned int[caseCount];

  // 각 케이스의 평균을 저장할 배열
  double* average = new double[caseCount];
  for(int i = 0; i < caseCount; i++)
  {
    cin >> studentCount[i];

    // 학생 수에 맞는 배열 생성
    testCases[i] = new unsigned int[studentCount[i]];

    // 점수 입력
    for(int j = 0; j < studentCount[i]; j++)
    {
      cin >> testCases[i][j];
    }
  }

  // 평균 계산 후 저장
  for(int i = 0; i < caseCount; i++)
  {
    average[i] = 0; // 초기화
    for(int j = 0; j < studentCount[i]; j++)
    {
      // 모든 점수 더하기
      average[i] += (double)testCases[i][j];
    }
    // 평균 계산
    average[i] /= studentCount[i];
  }

  // 비율 반올림해서 소수점 셋째 자리까지 출력
  double* ratio = new double[caseCount]; // 각 케이스의 비율을 저장할 배열
  unsigned int overAvgCount = 0; // 각 케이스에서 평균을 넘는 사람의 수
  for(int i = 0; i < caseCount; i++)
  {
    // 평균 넘는 사람 수 세기
    for(int j = 0; j < studentCount[i]; j++)
    {
      if(testCases[i][j] > average[i])
      {
        overAvgCount++;
      }
    }
    // 비율 계산
    ratio[i] = ((double)overAvgCount/(double)studentCount[i]) * 100.0f;

    // 소수점 셋째 자리에서 반올림 해 출력
    cout.precision(3);
    cout << fixed << ratio[i] << "%" << endl;

    overAvgCount = 0;
  }
  
  // 메모리 해제
  for(int i = 0; i < caseCount; i++)
  {
    delete[] testCases[i];
  }
  delete[] testCases;
  delete[] average;
  delete[] ratio;
  delete[] studentCount;
  return 0;
}