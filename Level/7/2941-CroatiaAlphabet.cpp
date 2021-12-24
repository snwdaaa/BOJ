#include <iostream>
using namespace std;

int main()
{
  string str; // 문자열
  int croatianCount = 0; // 크로아티아 문자 세기

  cin >> str;

  for(int i = 0; i < str.size(); i++)
  {
    
    if('a' <= str[i] && str[i] <= 'z')
    {
      // 크로아티아 문자인지 확인

      // 세 문자로 변경되는 크로아티아 알파벳
      if(i+2 < str.size()) // 가능한 인덱스를 초과하지 않도록 먼저 확인
      {
        // dž
        if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=')
        {
          croatianCount++;
          i += 2;
          continue;
        }
      }

      // 두 문자로 변경되는 크로아티아 알파벳
      if(i+1 < str.size())  // 가능한 인덱스를 초과하지 않도록 먼저 확인
      {
        // č
        if(str[i] == 'c' && str[i+1] == '=')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // ć
        else if(str[i] == 'c' && str[i+1] == '-')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // đ
        else if(str[i] == 'd' && str[i+1] == '-')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // lj
        else if(str[i] == 'l' && str[i+1] == 'j')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // nj
        else if(str[i] == 'n' && str[i+1] == 'j')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // š
        else if(str[i] == 's' && str[i+1] == '=')
        {
          croatianCount++;
          i += 1;
          continue;
        }
        // ž
        else if(str[i] == 'c' && str[i+1] == '=')
        {
          croatianCount++;
          i += 1;
          continue;
        }
      }

      // 크로아티아 알파벳이었다면 앞에서 continue가 되었기 때문에
      // 여기까지 온 문자는 일반 알파벳
      croatianCount++;
    }
  }

  cout << croatianCount << endl;

  return 0;
}