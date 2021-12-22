#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  string s; // 단어
  cin >> s;

  int alphaPos[26]; // 알파벳의 등장 여부를 저장할 배열
  for(int i = 0; i < 26; i++) // -1로 초기화
  {
    alphaPos[i] = -1;
  }
  
  for(int i = 0; i < s.size(); i++)
  {
    // 97 ~ 122 제한
    if(s[i] >= 97 && s[i] <= 122)
    {
      // 97로 나눈 나머지를 인덱스로
      if(alphaPos[s[i] % 97] == -1)
      {
        alphaPos[s[i] % 97] = i;
      }
    }
  }

  for(int i = 0; i < 26; i++) // -1로 초기화
  {
    cout << alphaPos[i] << " ";
  }
  cout << endl;

  return 0;
}