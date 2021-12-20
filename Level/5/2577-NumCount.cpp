#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int a, b, c;
  int mulResult;

  cin >> a;
  cin >> b;
  cin >> c;
  mulResult = a*b*c;

  // 자릿수 계산
  int digitHelper = 1;
  int digitCount = 1;
  while(mulResult % ((int)pow(10, digitHelper)) != mulResult)
  {
    digitCount++;
    digitHelper++;
  }

  int* resultArr = new int[digitCount];
  for(int i = 0; i < digitCount; i++)
  {
    resultArr[i] = (mulResult % (int)pow(10, i+1)) / (int)pow(10, i);
  }

  int numCount[10] = {0,}; // 0~9 갯수
  for(int i = 0; i < digitCount; i++)
  {
    switch(resultArr[i])
    {
      case 0:
        numCount[0]++;
        break;
      case 1:
        numCount[1]++;
        break;
      case 2:
        numCount[2]++;
        break;
      case 3:
        numCount[3]++;
        break;
      case 4:
        numCount[4]++;
        break;
      case 5:
        numCount[5]++;
        break;
      case 6:
        numCount[6]++;
        break;
      case 7:
        numCount[7]++;
        break;
      case 8:
        numCount[8]++;
        break;
      case 9:
        numCount[9]++;
        break;

    }
  }

  for(int i = 0; i <= 9; i++)
  {
    cout << numCount[i] << endl;
  }

  delete[] resultArr;
  return 0;
}