#include <iostream>
using namespace std;

int getUnitDigit(int num);
int getTensDigit(int num);
int getHundredsDigit(int num);

int main()
{
  int operand1, operand2;
  int num3, num4, num5;
  int result = 0;
  
  // 입력
  cin >> operand1;
  cin >> operand2;

  // (3)
  num3 = operand1 * getUnitDigit(operand2);
  cout << num3 << endl;

  // (4)
  num4 = (operand1 * getTensDigit(operand2));
  cout << num4 << endl;

  // (5)
  num5 = (operand1 * getHundredsDigit(operand2));
  cout << num5 << endl;

  // (6)
  result = num3 + (num4 * 10) + (num5 * 100);
  cout << result << endl;
}

// 1의 자리 수 구하는 함수
int getUnitDigit(int num)
{
  return num % 10;
}

// 10의 자리 수 구하는 함수
int getTensDigit(int num)
{
  int unitDigit = getUnitDigit(num);

  return ((num % 100) - unitDigit) / 10;
}

int getHundredsDigit(int num)
{
  int unitDigit = getUnitDigit(num);
  int tensDigit = getTensDigit(num) * 10;

  return ((num % 1000) - tensDigit - unitDigit) / 100;
}