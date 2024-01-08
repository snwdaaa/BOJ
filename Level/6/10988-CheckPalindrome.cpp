// 팰린드롬(회문) 체크

#include <iostream>

int main()
{
    std::string str;
    std::cin >> str;

    int i, j;
    for (i = 0, j = str.length() - 1; i <= j; i++, j--)
    {      
        if (str.at(i) != str.at(j)) // 문자열 양 끝에서 하나씩 비교하면서 다른거 나오면 회문 아니므로 0 출력 후 종료
        {
            std::cout << "0";
            return 0;
        }
    }

    std::cout << "1"; // 여기까지 오면 회문이므로 
    return 0;
}