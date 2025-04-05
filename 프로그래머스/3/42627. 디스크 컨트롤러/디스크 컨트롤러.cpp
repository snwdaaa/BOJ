#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) 
{
    sort(jobs.begin(), jobs.end()); // 요청시간 순으로 정렬

    int time = 0; // 현재 시간
    int total = 0; // 총 대기 시간
    int index = 0; // jobs 배열 인덱스
    int count = 0; // 처리한 작업 수

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    while (count < jobs.size())
    {
        // 현재 시간까지 들어온 모든 작업을 큐에 추가함
        while (index < jobs.size() && jobs[index][0] <= time)
        {
            pq.push({jobs[index][1], jobs[index][0]}); // {소요시간, 요청시각}
            index++;
        }

        if (!pq.empty())
        {
            // pq의 맨 위에 있는 값에서 소요시간과 요청시각을 가져옴
            int duration = pq.top().first;
            int request = pq.top().second;
            pq.pop();

            time += duration; // 현재시간에 소요시간 더하기
            total += (time - request); // 작업 끝 -> 현재시각 - 요청시각
            count++; // 작업 처리 개수 + 1
        }
        else
        {
            // 처음에 들어온 작업이 없는 경우, 첫 번째 작업의 시간부터 시작
            time = jobs[index][0];
        }
    }

    return total / jobs.size();
}