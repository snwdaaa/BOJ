#include <iostream>
using namespace std;

int d(int num)
{
  int sum = num;

  while(1)
  {
    if(num == 0)
    {
      break;
    }

    sum += (num % 10);
    num /= 10;
  }

  return sum;
}

int main()
{
  bool nums[100001]; // 인덱스가 셀프 넘버가 아니면 true, 셀프 넘버면 false를 반환
  int idx;

  for(int i = 0; i < 10001; i++)
  {
    idx = d(i);

    if(idx < 10001)
    {
      nums[idx] = true;
    }
  }

  for(int i = 0; i < 10001; i++)
  {
    if(nums[i] == false)
    {
      cout << i << endl;
    }
  }

  return 0;
}