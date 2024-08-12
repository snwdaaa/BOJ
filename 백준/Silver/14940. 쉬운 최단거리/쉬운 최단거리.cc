#include <bits/stdc++.h>
using namespace std;

int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int inputMap[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// 초기화
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + 1001, -1);
	}

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> inputMap[i][j];

			if (inputMap[i][j] == 0) dist[i][j] = 0; // 갈 수 없는 땅
			if (inputMap[i][j] == 2) { // 목표 지점
				dist[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	// BFS
	while (!q.empty()) {
		auto currentPos = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int newX = currentPos.second + dx[dir];
			int newY = currentPos.first + dy[dir];

			if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
			if (inputMap[newY][newX] != 1) continue;

			inputMap[newY][newX] = 0; // 방문 처리
			q.push(make_pair(newY, newX));
			dist[newY][newX] = dist[currentPos.first][currentPos.second] + 1; // 거리 계산
		}
	}

	// dist 배열 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}