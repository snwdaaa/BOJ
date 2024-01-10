// 글자 -> A~Z, a~z, 0~9
// 글자를 수평으로 일렬로 붙여서 단어를 만듦
// 그 아래에 또 다른 글자들을 붙여 또 다른 단어를 만듦
// 이 과정으로 다섯 개의 단어를 만듦

// 한 줄의 단어는 글자들을 빈칸 없이 연속으로 나열해 최대 15개의 글자 & 각 줄의 글자의 개수는 다를 수 있음
// 각 단어의 첫 번째 글자들을 세로로 읽음 -> 두 번째 글자들을 세로로 읽음 -> ...
// 글자가 있으면 읽고 없으면 읽지 않고 그 다음 글자를 읽음
// 이렇게 읽는 글자들을 공백 없이 연속해서 출력

#include <iostream>

int main()
{
    char words[5][15] = {'\0', };
    for (int i = 0; i < 5; i++)
    {
        std::cin >> words[i];
    }

    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (words[i][j] != '\0') std::cout << words[i][j];
        }
    }

    return 0;
}