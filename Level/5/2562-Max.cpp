#include <iostream>
using namespace std;

int main()
{
  int arr[9];
  for(int i = 0; i < 9; i++)
  {
    cin >> arr[i];
  }

  int max, maxIdx;
  max = arr[0];

  for(int i = 0; i < 9; i++)
  {
    if(max < arr[i])
    {
      max = arr[i];
      maxIdx = i+1;
    }
  }

  cout << max << endl << maxIdx << endl;

  return 0;
}