#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // 스택에 하나씩 집어넣음
    // 스택에 특정 수가 맨 위에 있다면, 그 수는 스택에 집어넣지 않고 스킵
    // 아니라면 스택에 집어넣음
    // arr에 있는 모든 값에 대한 검사가 끝났다면 스택에서 하나씩 꺼내 answer에 집어넣음
    // 시간 복잡도 => O(n)  
    
    for (auto it = arr.begin(); it != arr.end(); it++)
        if (answer.empty() || answer.back() != *it) // answer가 비어있거나 top에 이미 집어넣은 수가 있지 않은 경우에만 push
            answer.push_back(*it);

    return answer;
}