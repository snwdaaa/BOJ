#include <iostream>
#include <string>
using namespace std;

int main()
{
  string num1, num2; // 입력 받는 0이 없는 같지 않은 세 자리 수
  string num1_inverted, num2_inverted; // 반전된 문자열

  // 입력 받기
  cin >> num1;
  cin >> num2;

  // num1, num2를 반전한 후 _inverted 변수에 대입
  for(int i = 0; i < 3; i++)
  {
    num1_inverted[i] = num1[2 - i];
    num2_inverted[i] = num2[2 - i];
  }

  int num1_int, num2_int; // 문자열을 정수로 변환한 결과를 저장할 변수
  // 문자열을 정수로 변환
  num1_int = stoi(num1_inverted);
  num2_int = stoi(num2_inverted);

  // 둘 중 더 큰 수를 출력
  if(num1_int >= num2_int)
  {
    cout << num1_int << endl;
  }
  else
  {
    cout << num2_int << endl;
  }

  return 0;
}