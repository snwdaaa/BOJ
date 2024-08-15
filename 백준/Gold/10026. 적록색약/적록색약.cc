#include <bits/stdc++.h>
using namespace std;

int n;
char normalMatrix[100][100];
char blindedMatrix[100][100]; // normalMatrix에서 G를 모두 R로 바꿈
queue<pair<int, int>> normalQueue;
queue<pair<int, int>> blindedQueue;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int blindedCnt = 0; // 적록 색약이 본 구역 개수
int normalCnt = 0; // 정상인이 본 구역 개수

void BFS(int order) { // order: 0(R), 1(B), 2(G)
	while (!normalQueue.empty()) {
		auto currentPos = normalQueue.front(); normalQueue.pop();

		for (int i = 0; i < 4; i++) {
			int newX = currentPos.first + dx[i];
			int newY = currentPos.second + dy[i];

			if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
			if (normalMatrix[newY][newX] == 'V') continue; // 이미 방문했으면 continue
			if (order == 0 && normalMatrix[newY][newX] != 'R') continue;
			if (order == 1 && normalMatrix[newY][newX] != 'B') continue;
			if (order == 2 && normalMatrix[newY][newX] != 'G') continue;

			// 방문 처리
			normalQueue.push(make_pair(newX, newY));
			normalMatrix[newY][newX] = 'V';
		}
	}
}

void BlindedBFS(int order) { // order: 0(R), 1(B)
	while (!blindedQueue.empty()) {
		auto currentPos = blindedQueue.front(); blindedQueue.pop();

		for (int i = 0; i < 4; i++) {
			int newX = currentPos.first + dx[i];
			int newY = currentPos.second + dy[i];

			if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
			if (blindedMatrix[newY][newX] == 'V') continue; // 이미 방문했으면 continue
			if (order == 0 && blindedMatrix[newY][newX] != 'R') continue;
			if (order == 1 && blindedMatrix[newY][newX] != 'B') continue;

			// 방문 처리
			blindedQueue.push(make_pair(newX, newY));
			blindedMatrix[newY][newX] = 'V';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin.ignore(); // 개행문자 무시
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			normalMatrix[i][j] = line.at(j);
			blindedMatrix[i][j] = line.at(j);
		}
	}
	
	for (int i = 0; i < n; i++) { // 적록색약 배열을 만듦 -> 초록색도 빨간색으로 만들어버림
		for (int j = 0; j < n; j++) {
			if (blindedMatrix[i][j] == 'G') {
				blindedMatrix[i][j] = 'R';
			}
		}
	}

	
	for (int k = 0; k < 3; k++) { // 정상 -> R -> B -> G 순서로
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (normalMatrix[i][j] == 'V') continue; // 이미 방문한 곳이면 스킵
				if (k == 0 && (normalMatrix[i][j] == 'B' || normalMatrix[i][j] == 'G')) continue; // R 검사할 때 B, G는 스킵
				if (k == 1 && normalMatrix[i][j] == 'G') continue; // B 검사할 때 G는 스킵

				normalQueue.push(make_pair(j, i));
				normalMatrix[i][j] = 'V';
				BFS(k);
				normalCnt++;
			}
		}
	}
	
	for (int k = 0; k < 2; k++) { // 적록색약 -> R에 대해 BFS -> B에 대해 BFS
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (blindedMatrix[i][j] == 'V') continue; // 이미 방문한 곳이면 스킵
				if (k == 0 && blindedMatrix[i][j] == 'B') continue; // R 검사할 때 B는 스킵

				blindedQueue.push(make_pair(j, i));
				blindedMatrix[i][j] = 'V';
				BlindedBFS(k);
				blindedCnt++;
			}
		}
	}
	
	cout << normalCnt << " " << blindedCnt;
}