#include <bits/stdc++.h>
using namespace std;

int subinPos, brotherPos;
int dist[100001]; // 일직선상에서 수빈이가 처음 위치에서 움직여서 동생을 찾을 때까지의 거리
queue<int> q; // 다음으로 움직일 곳

void BFS() {
	while (!q.empty()) {
		int currentPos = q.front(); q.pop();

		for (int i = 0; i < 3; i++) {
			switch (i) {
				case 0: // X - 1
					if (currentPos - 1 < 0 || currentPos - 1 > 100000) break; // 범위
					if (dist[currentPos - 1] != -1) break; // 이동하지 않은 곳으로만 이동
					dist[currentPos - 1] = dist[currentPos] + 1;
					q.push(currentPos - 1);
					break;
				case 1: // X + 1
					if (currentPos + 1 < 0 || currentPos + 1 > 100000) break;
					if (dist[currentPos + 1] != -1) break;
					dist[currentPos + 1] = dist[currentPos] + 1;
					q.push(currentPos + 1);
					break;
				case 2: // 2 * X
					if (2 * currentPos < 0 || 2 * currentPos > 100000) break;
					if (dist[2 * currentPos] != -1) break;
					dist[2 * currentPos] = dist[currentPos] + 1;
					q.push(2 * currentPos);
					break;
			}
		}

		if (dist[brotherPos] != -1) return; // 동생 찾으면 종료
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subinPos >> brotherPos;
	fill(dist, dist + 100001, -1); // -1로 초기화

	dist[subinPos] = 0;
	q.push(subinPos);
	BFS();
	
	cout << dist[brotherPos];
}