#include <iostream>
using namespace std;

int main()
{
  int x, y;

  cin >> x;
  cin >> y;

  bool quadrant1 = (x > 0) && (y > 0);
  bool quadrant2 = (x < 0) && (y > 0);
  bool quadrant3 = (x < 0) && (y < 0);
  bool quadrant4 = (x > 0) && (y < 0);

  if(quadrant1)
  {
    cout << "1" << endl;
  }
  else if(quadrant2)
  {
    cout << "2" << endl;
  }
  else if(quadrant3)
  {
    cout << "3" << endl;
  }
  else if(quadrant4)
  {
    cout << "4" << endl;
  }

  return 0;
}