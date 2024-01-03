#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int charCount;
  cin >> charCount;

  char* nums = new char[charCount];
  int sum = 0;

  for(int i = 0; i < charCount; i++)
  {
    cin >> nums[i];
    sum += atoi(&nums[i]);
  }

  cout << sum << endl;

  delete[] nums;
  return 0;
}