#include <iostream>
using namespace std;

int main()
{
  unsigned int year;

  cin >> year;

  // 윤년의 조건
  bool condition1 = ((year % 4) == 0) && ((year % 100) != 0); // 4의 배수이면서 100의 배수가 아닐 때
  bool condition2 = (year % 400) == 0; // 400의 배수일 때

  if(condition1 || condition2)
  {
    cout << "1" << endl;
  }
  else
  {
    cout << "0" << endl;
  }

  return 0;
}