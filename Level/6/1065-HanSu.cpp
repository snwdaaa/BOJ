#include <iostream>
#include <cmath>
using namespace std;

int HansuCount(int N, int digit)
{
  if(digit == 1 || digit == 2)
  {
    // 한 자리수일 경우 등차가 0인 등차수열이고
    // 두 자리수일 경우 십의 자리 수와 일의 자리 수 사이의 등차는 항상 일정하므로
    // 1을 리턴하고 함수 종료
    return 1;
  }
  else
  {
    bool isSequence = true; // 등차 수열 여부를 확인하는 bool 변수
    int* numArray = new int[digit]; // 각 자리수를 저장할 배열
    int* diff = new int[digit - 1]; // 각 자리수의 등차를 저장할 배열

    // 각 자리수 구하기
    for(int i = 0; i < digit; i++)
    {
      numArray[(digit - 1) - i] = N % 10;
      N /= 10;
    }

    // 각 자리수 사이의 등차 구하기
    for(int i = 1; i < digit; i++)
    {
      diff[i-1] = numArray[i-1] - numArray[i]; 
    }

    // 모든 등차가 같은지 확인
    for(int i = 1; i < digit - 1; i++)
    {
      if(diff[0] == diff[i])
      {
        isSequence = true;
      }
      else
      {
        // 등차 수열이 아닌 것이 확인되면 바로 빠져나오기
        isSequence = false;
        break;
      }
    }

    // 메모리 해제
    delete[] numArray;
    delete[] diff;

    // 등차수열이면 1, 아니면 0 리턴
    if(isSequence == true)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

int main()
{
  int N;
  cin >> N;

  int count = 0;  // 등차수열의 수를 셀 정수형 변수
  for(int i = 1; i <= N; i++)
  {
    // 주어진 수 N의 자리수 확인
    int digitCount = 1;
    while(i % ((int)pow(10, digitCount)) != i)
    {
      digitCount++;
    }

    count += HansuCount(i, digitCount);
  }

  cout << count << endl;

  return 0;
}