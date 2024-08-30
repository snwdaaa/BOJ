#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> q;
int line[100001]; // 이동 거리를 저장할 배열

void LineBFS() {
	while (!q.empty()) {
		auto x = q.front(); q.pop();
		int nextPos[3] = { x - 1, x + 1, x * 2 };

		// X-1, X+1, 2*X 모두 범위, 이미 방문한 곳인지, K와 같은 지 확인
		for (int i = 0; i < 3; i++) {
			int nextIdx = nextPos[i];
			if (nextIdx < 0 || nextIdx >= 100001) continue; // 범위
			if (line[nextIdx] != -1) continue; // 방문 여부
			line[nextIdx] = line[x] + 1;
			q.push(nextIdx);
		}

		if (line[K] != -1) return; // 동생 위치 찾은 경우 종료
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	fill(line, line + 100001, -1); // -1로 초기화

	line[N] = 0;
	q.push(N); // 수빈이의 첫 시작 위치를 큐에 추가

	LineBFS();

	cout << line[K];
}