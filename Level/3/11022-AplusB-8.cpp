#include <iostream>
using namespace std;

int main()
{
  unsigned int caseSize = 0;
  cin >> caseSize;

  int* testCases = new int[caseSize];
  int* caseOperands = new int[caseSize * 2];
  int a, b;

  for(int i = 0, caseIdx = 0; caseIdx < caseSize; i+=2, caseIdx++)
  {
    cin >> a;
    cin >> b;

    testCases[caseIdx] = a+b;
    caseOperands[i] = a;
    caseOperands[i+1] = b;
  }

  for(int i = 0, caseIdx = 0; caseIdx < caseSize; i+=2, caseIdx++)
  {
    cout << "Case #" << (caseIdx + 1) << ": " << caseOperands[i] << " + " << caseOperands[i+1] << " = " << testCases[caseIdx] << endl;
  }
  delete[] testCases;
  delete[] caseOperands;

  return 0;
}