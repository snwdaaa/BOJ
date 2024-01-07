// C++ 책 472 페이지
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str, word;
  string delimeter(" "); // 구분 문자
  string::size_type wStart, wEnd; // 단어의 시작과 마지막을 나타내는 변수
  string::size_type npos = -1;  // 백준에서는 오류가 떠서 = -1 써줘야 함

  // 문자열 입력
  getline(cin, str);

  // 문자열 탐색하면서 개수 세기
  int wordCount = 0;  // 단어의 개수
  wStart = str.find_first_not_of(delimeter, 0); // 0번 인덱스에서 시작해 delimeter가 아닌 문자가 처음으로 나오는 곳을 찾음
  while(wStart < npos)
  {
    wEnd = str.find_first_of(delimeter, wStart); // wStart에서 시작해 delimeter가 처음으로 나오는 곳을 찾음
    wordCount++; // 단어 개수 증가
    wStart = str.find_first_not_of(delimeter, wEnd); // wEnd에서 시작해 delimeter가 아닌 문자가 처음으로 나오는 곳을 찾음
  }

  cout << wordCount << endl;

  return 0;
}