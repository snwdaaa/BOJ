#include <bits/stdc++.h>
using namespace std;

int R, C;
string maze[1000];
int jihunDist[1000][1000]; // 지훈이의 이동 거리 (시간으로 생각)
int fireDist[1000][1000]; // 불의 이동 거리 (시간으로 생각)
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C; // 행렬 크기 입력

	for (int i = 0; i < R; i++) { // dist 배열들 -1로 초기화	
		fill(jihunDist[i], jihunDist[i] + C, -1);
		fill(fireDist[i], fireDist[i] + C, -1);
	}

	for (int i = 0; i < R; i++)
		cin >> maze[i];

	queue<pair<int, int>> jihunQueue;
	queue<pair<int, int>> fireQueue;
	for (int i = 0; i < R; i++) { // 지훈, 불 시작 위치 찾기 & 초기화
		for (int j = 0; j < C; j++)
		{
			if (maze[i][j] == 'F') {
				fireQueue.push(make_pair(j, i)); // (x, y)
				fireDist[i][j] = 0;
			}
			if (maze[i][j] == 'J') {
				jihunQueue.push(make_pair(j, i)); // (x, y)
				jihunDist[i][j] = 0;
			}
		}
	}

	// 불 먼저 BFS
	while (!fireQueue.empty()) {
		auto currentPos = fireQueue.front(); fireQueue.pop(); // 큐의 앞에서 pop
		for (int i = 0; i < 4; i++) {
			int newX = currentPos.first + dx[i];
			int newY = currentPos.second + dy[i];

			if (newX < 0 || newX >= C || newY < 0 || newY >= R) continue; // 범위 체크
			if (fireDist[newY][newX] >= 0 || maze[newY][newX] == '#') continue; // 이미 방문한 곳 or 벽이면 체크

			fireDist[newY][newX] = fireDist[currentPos.second][currentPos.first] + 1; // 새로 이동할 위치에 대해 거리 + 1
			fireQueue.push(make_pair(newX, newY));
		}
	}

	// 지훈이 BFS
	while (!jihunQueue.empty()) {
		auto currentPos = jihunQueue.front(); jihunQueue.pop(); // 큐의 앞에서 pop
		for (int i = 0; i < 4; i++) {
			int newX = currentPos.first + dx[i];
			int newY = currentPos.second + dy[i];

			// 범위 벗어남 -> 탈출 성공
			// 큐에 거리순으로 들어가므로 탈출 성공한 곳 바로 출력
			if (newX < 0 || newX >= C || newY < 0 || newY >= R) {
				cout << jihunDist[currentPos.second][currentPos.first] + 1;
				return 0;
			}

			if (jihunDist[newY][newX] >= 0 || maze[newY][newX] == '#') continue; // 이미 방문 or 벽인 경우
			if (fireDist[newY][newX] != -1 && jihunDist[currentPos.second][currentPos.first] + 1 >= fireDist[newY][newX]) continue; // 이미 불이 지나간 곳이면서 지훈이가 불보다 늦게 도착했다면

			jihunDist[newY][newX] = jihunDist[currentPos.second][currentPos.first] + 1; // 새로 이동할 위치에 대해 거리 + 1
			jihunQueue.push(make_pair(newX, newY));
		}
	}

	cout << "IMPOSSIBLE"; // 지훈이 BFS에서 리턴 못 만났으면 탈출 못 한거
}