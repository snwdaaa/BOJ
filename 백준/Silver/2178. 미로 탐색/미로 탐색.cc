// 미로 최대 10,000칸 => O(N^2)까지 가능
// (1, 1) -> (N, M)까지 최단 거리 => 오른쪽 아래로 계속 움직이면 됨 => 오른쪽 -> 아래 -> 왼쪽 -> 위 순서로 검사
// 동시에 dist 배열에서 시작점에서부터 각 점까지의 거리를 저장 -> 마지막에 dist[n][m] + 1 출력 (출발점 포함)

#include <bits/stdc++.h>
using namespace std;

int n, m;
int maze[101][101] = { 0, }; // 0번 인덱스 사용 X
int dist[101][101]; // 출발점부터의 거리를 계산할 배열
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

void BFS(int x, int y)
{
	while (!q.empty())
	{
		// 큐에서 꺼내기
		pair<int, int> currentPos = q.front(); q.pop();

		int newX, newY;
		for (int i = 0; i < 4; i++)
		{
			// 새롭게 이동할 좌표 만들기
			newX = currentPos.first + dx[i];
			newY = currentPos.second + dy[i];
	
			if (newX < 0 || newX > m || newY < 0 || newY > n) continue; // 범위 벗어나는 지 확인

			if (maze[newY][newX] && dist[newY][newX] == -1) // 이동할 수 있는 칸이고, 아직 거리를 계산하지 않았다면
			{
				q.push(make_pair(newX, newY)); // 큐에 추가

				// dist에 저장할 거리 계산
				dist[newY][newX] = dist[currentPos.second][currentPos.first] + 1; // 인접한 점들까지의 거리 => 현재 위치까지의 거리 + 1
			}		
		}
		
		BFS(newX, newY); // 네 방향으로 이동할 수 있는 모든 점에 대해 거리를 계산한 후 큐의 맨 앞에 있는 곳으로 이동
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int y = 1; y <= n; y++)
	{
		string inputLine; // 붙어서 입력으로 주어짐 -> 문자열로 받은 다음 하나씩 가져오기
		cin >> inputLine;

		for (int x = 1; x <= m; x++)
		{
			maze[y][x] = int(inputLine.at(x - 1)) - 48; // 49: 1
		}
	}
	for (int i = 0; i <= n; i++) fill(dist[i], dist[i] + m + 1, -1); // dist 배열 각 줄마다 -1로 채우기

	// 출발점 관련 초기값 설정
	q.push(make_pair(1, 1));
	maze[1][1] = 0;
	dist[1][1] = 0;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (maze[y][x])
			{
				BFS(x, y);
			}
		}
	}

	cout << dist[n][m] + 1; // +1 -> 출발점 포함
}