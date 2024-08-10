#include <bits/stdc++.h>
using namespace std;

int n;
int house[25][25];
int visited[25][25];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
int complexCnt = 0; // 단지 개수
int houseCnt; // 단지 내에 있는 집 수
int houseIdx = 1; // 단지 번호
vector<int> v; // 각 단지별 집 수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		fill(house[i], house[i] + n, 0); // house 배열 초기화
		fill(visited[i], visited[i] + n, 0); // visited 배열 초기화
	}

	// 지도 입력
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;

		for (int j = 0; j < n; j++) {
			house[i][j] = int(line.at(j)) - 48; // 정수로 변환
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (house[i][j] == 0) continue;		

			complexCnt++; // 단지 개수 + 1
			houseCnt = 1; // 단지별 집 개수 1으로 설정 (시작점 포함)

			house[i][j] = 0;
			visited[i][j] = houseIdx;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				auto currentPos = q.front(); q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int newX = currentPos.second + dx[dir];
					int newY = currentPos.first + dy[dir];

					if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
					if (house[newY][newX] == 0 || visited[newY][newX] != 0) continue;

					house[newY][newX] = 0; // 방문 처리
					visited[newY][newX] = houseIdx;
					houseCnt++; // 단지별 집 개수 증가
					q.push(make_pair(newY, newX));
				}
			}

			houseIdx++; // 단지 번호 증가
			v.push_back(houseCnt);
		}
	}

	sort(v.begin(), v.end()); // 벡터 정렬

	cout << complexCnt << '\n';
	for (auto& elem : v) {
		cout << elem << '\n';
	}
}