#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> stk;
    
    for (char ch : s)
    {
        if (stk.empty() || ch == '(')
            stk.push(ch);
        else // 닫는 괄호
        {
            stk.pop(); // 여는 괄호 가지고 나감
        }
    }
    
    if (!stk.empty()) // 스택에 괄호가 남아있으면 바르게 짝지어지지 않은 것
        answer = false;

    return answer;
}