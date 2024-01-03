#include <iostream>
using namespace std;

int main()
{
  unsigned int caseSize = 0;
  cin >> caseSize;

  int* testCases = new int[caseSize];
  int a, b;

  for(int i = 0; i < caseSize; i++)
  {
    cin >> a;
    cin >> b;

    testCases[i] = a+b;
  }

  for(int i = 0; i < caseSize; i++)
  {
    cout << "Case #" << (i+1) << ": " << testCases[i] << endl;
  }
  delete[] testCases;

  return 0;
}