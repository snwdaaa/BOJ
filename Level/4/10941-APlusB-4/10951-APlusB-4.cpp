#include <iostream>
using namespace std;

int main()
{
  int a, b;
  int sum;

  cin >> a;
  cin >> b;

  while(!cin.eof())
  {
    sum = a + b;
    cout << sum << endl;

    cin >> a;
    cin >> b;
  }
}