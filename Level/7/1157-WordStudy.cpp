// 문자열 입력 받으면 전부 대문자로 바꿔버리고 거기서 비교 시작하기
// 가장 많이 사용된 알파벳 -> 크기 26인 배열 만들고 거기에 각 칸마다 나온 횟수
// 저장함. 최대값은 배열 한 칸씩 방문하면서 max 정하기 & 마지막 max의 idx도 구하기 (65 + 마지막 idx)
// 많이 사용된 알파벳이 여러개 존재 확인? -> 한 번 슥 훑고 최대값 가진 상태로 다시 탐색
// 이 때 마지막 max와 인덱스는 다른데 값은 같으면 여러개 존재 -> ? 출력

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  // 단어 입력
  string word;
  cin >> word;

  // 알파벳이 나온 횟수를 저장할 배열(대문자)
  int alphaCount[26] = {0, };

  // 모두 대문자로 바꾼 후 나온 횟수를 배열에 저장하기
  for(int i = 0; i < word.size(); i++)
  {
    // 문자 확인에 필요한 조건
    bool isAlphaLower = word[i] >= 97 && word[i] <= 122;

    if(isAlphaLower) // 소문자일 때
    {
      word[i] = toupper(word[i]); // 대문자로 변환    
    }

    alphaCount[word[i] % 65]++;
  }

  // 최대값 찾기
  // 마지막으로 나온 최대값의 인덱스가 maxIdx에 저장됨
  int maxIdx = 0;
  int maxValue = alphaCount[0];
  for(int i = 0; i < 26; i++)
  {
    if(maxValue <= alphaCount[i])
    {
      maxIdx = i;
      maxValue = alphaCount[i];
    }
  }

  // 가장 많이 사용된 알파벳이 여러 개 있는지 확인
  // 마지막으로 나온 최대값 요소보다 앞에 있는 요소 중에 최대값이 있다면
  // 알파벳이 여러 개 존재하는 것
  bool hasMultipleMax = false;
  for(int i = 0; i < 26; i++)
  {
    if(maxValue == alphaCount[i])
    {
      if(maxIdx != i)
      {
        hasMultipleMax = true;
      }
    }
  }

  // 최대값이 여러개면 ? 출력
  if(hasMultipleMax == true)
  {
    cout << "?" << endl;
  }
  else // 대문자로 출력하므로 'A'(65) 에다 maxIdx 값을 더함
  {
    cout << static_cast<char>('A' + maxIdx) << endl;
  }

  return 0;
}