// 그룹 단어 체크하기 -> 두 가지 경우

// 1. 문자가 연속적으로 나옴 (ccazzzbb)
// 문자가 연속인지 확인하는 isSequence 변수(true로 초기화), 한 번이라도 나온 문자를 저장할 스택
// 문자 검사 순서
// (두 번째 문자부터) 이전에 나온 문자와 다르면 isSequence = false, 같으면 true
// 스택에 없는 문자면 배열에 저장(push_back) 후 진행, 있으면 isSequence 확인. 이때 false면 연속된게 X -> break
// break 안 당하고 끝까지 가면 그룹단어

// 2. 모두가 서로 다른 문자

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(void)
{
    using namespace std;
    int N;
    cin >> N;
    vector<string> str(N);
    for (int i = 0; i < N; ++i) cin >> str[i];
    
    int groupWordCount = 0; // 그룹 단어 개수
    bool isGroupWord;   // 그룹 단어 여부
    vector<char> usedCharacter; // 사용된 문자를 저장할 배열
    for (int i = 0; i < N; ++i)
    {
        isGroupWord = true;
        usedCharacter = {}; // 배열 초기화
        for (int j = 0; j < str[i].length(); ++j)
        {
            if (j == 0) usedCharacter.push_back(str[i][j]);
            else
            {
                // 이전에 나온 문자와 같은지 (연속인지 확인)
                if (str[i][j] == str[i][j-1]) continue;
                else // 연속이 아닐 떄
                {
                    // 이전에 나온 문자가 있는지 확인
                    if (find(usedCharacter.begin(), usedCharacter.end(), str[i][j]) == usedCharacter.end())
                    {
                        // 문자가 없으면 (새로운 문자면)
                        usedCharacter.push_back(str[i][j]); // 문자 저장 후 진행
                    }
                    else
                    {
                        // 연속이 아니고 이미 문자가 나왔으므로 그룹 단어가 아님
                        isGroupWord = false;
                        break;
                    }
                }
            }
        }
        if (isGroupWord) groupWordCount++;
    }
    cout << groupWordCount << endl;
    return 0;
}