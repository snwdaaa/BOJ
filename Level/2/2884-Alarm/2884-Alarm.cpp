#include <iostream>
using namespace std;

int main()
{
  int hour, min;

  cin >> hour;
  cin >> min;

  if((min - 45) < 0)
  {
    if((hour - 1) < 0)
    {
      hour = 23;
    }
    else
    {
      hour--;
    }
    min = 60 + (min-45);
  }
  else
  {
    min -= 45;
  }

  cout << hour << " " << min << endl;

  return 0;
}