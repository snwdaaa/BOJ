#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
        q.push_back(make_pair(i, priorities[i])); // (location, priority)
    
    int execOrder = 1; // 실행 순서
    while (!q.empty())
    {
        auto front = q[0]; q.erase(q.begin());
        bool hasHigherPrior = false; // 큐 안에 우선순위가 더 높은 프로세스가 있는지?
        for (auto it = q.begin(); it != q.end(); it++)
            if (front.second < it->second)
                hasHigherPrior = true;
        if (hasHigherPrior) // 우선순위가 더 높은 프로세스가 있으면 다시 큐에 넣음
            q.push_back(front);
        else
        {
            if (front.first == location) // 찾는 프로세스의 위치와 같으면
                answer = execOrder;
            execOrder++;
        }

        
    }
    
    return answer;
}