#include <iostream>
using namespace std;

int main()
{
  int num[10];

  int diffRemainder = 0; // 서로 다른 나머지
  int remainders[10];

  // 입력
  for(int i = 0; i < 10; i++)
  {
    cin >> num[i];
    remainders[i] = num[i] % 42;
  }

  int equalCount;
  // 서로 다른 나머지 계산
  for(int i = 0; i < 10; i++)
  {  
    equalCount = 0;
    for(int j = i+1; j < 10; j++)
    {
      if(remainders[i] == remainders[j])
      {
        equalCount++;
      }
    }

    if(equalCount == 0)
    {
      diffRemainder++;
    }
  }

  cout << diffRemainder << endl;

  return 0;
}