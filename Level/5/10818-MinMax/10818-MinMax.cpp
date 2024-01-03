#include <iostream>
using namespace std;

int main()
{
  int size;
  cin >> size;

  int* arr = new int[size];
  for(int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  int min, max;
  min = arr[0];
  max = arr[size - 1];

  for(int i = 0; i < size; i++)
  {
    if(min > arr[i])
    {
      min = arr[i];
    }

    if(max < arr[i])
    {
      max = arr[i];
    }
  }

  cout << min << " " << max << endl;

  delete[] arr;

  return 0;
}