#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a);

int main()
{
  vector<int> integers;

  int numCount; // 정수의 개수
  int num; // 단계마다 벡터에 밀어넣기 위해 사용되는 정수형 변수

  cin >> numCount;

  for(int i = 0; i < numCount; i++)
  {
    cin >> num;
    integers.push_back(num); // 벡터에 정수 밀어넣기
  }

  cout << sum(integers);

  return 0;
}

long long sum(vector<int> &a)
{
  long long ans = 0;

  for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
  {
    ans += *iter;
  }

  return ans;
}

// 정답
/*
#include <vector>
using namespace std;
long long sum(vector<int> &a)
{
  long long ans = 0; // 합

  for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
  {
    ans += *iter;
  }

  return ans;
}
*/