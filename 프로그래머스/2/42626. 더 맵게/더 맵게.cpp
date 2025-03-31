#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); // O(n)
    
    // 모든 스코빌 지수가 K 이상인지 확인할 방법
    // => 최소 힙의 top 값이 K보다 큰지 확인
    
    // O(logn * logn)
    while (pq.top() < K)
    {
        if (pq.size() == 1) // 하나만 남았는데 K보다 작으면 K를 만들 수 없음
            return -1;
        
        int smallest = pq.top(); pq.pop();
        int secondSmallest = pq.top(); pq.pop();
        int mixed = smallest + (2 * secondSmallest);
        pq.push(mixed);
        answer++;
    }
    
    return answer;
}