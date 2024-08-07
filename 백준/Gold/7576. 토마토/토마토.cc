#include <bits/stdc++.h>
using namespace std;

int m, n;
int box[1001][1001]; // 0번 인덱스 사용 X
int dist[1001][1001];
queue<pair<int, int>> q; // (X, Y)
int dy[4] = { -1, 1, 0, 0 }; // 상하좌우 순서로 이동
int dx[4] = { 0, 0, -1, 1 };

void BFS()
{
	while (!q.empty())
	{
		auto currentPos = q.front(); q.pop(); // 큐 맨 앞에서 꺼내기

		int newX, newY;
		for (int i = 0; i < 4; i++) // 상하좌우에 있는 토마토에 대해 방문 준비
		{
			newX = currentPos.first + dx[i];
			newY = currentPos.second + dy[i];

			if (newX <= 0 || newX > m || newY <= 0 || newY > n) continue; // 범위를 벗어나면
			if (box[newY][newX] == 1 || box[newY][newX] == -1) continue; // 새로운 좌표의 토마토가 이미 익었거나, 들어있지 않은 칸이면

			dist[newY][newX] = dist[currentPos.second][currentPos.first] + 1; // 그 토마토에 대해 일수 + 1
			box[newY][newX] = 1; // 익은 것으로 처리
			q.push(make_pair(newX, newY)); // 큐에 추가
		}

		BFS(); // 방문 처리
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n; // 상자 크기 입력

	// 상자에 저장된 토마토 정보 입력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> box[i][j];

			// 시작점의 위치를 미리 큐에 저장
			if (box[i][j] == 1)
			{
				q.push(make_pair(j, i)); // (X, Y)
			}
			else if (box[i][j] == 0)
			{
				dist[i][j] = -1;
			}
			else if (box[i][j] == -1) // 빈 칸인 경우
			{
				dist[i][j] = -2;
			}
		}
	}

    BFS();

	// 만약 익지 않은 토마토가 하나라도 있다면 -1을 출력 후 종료, 아니면 모두 익는데 걸린 최소 날짜(dist에서 가장 큰 수) 출력
	int result = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				if (dist[i][j] == -2) continue; // 빈 칸인 경우 스킵
				result = max(result, dist[i][j]);
			}
		}
	}

	cout << result;
}