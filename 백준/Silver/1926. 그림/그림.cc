// BFS 문제
// 도화지에 있는 그림의 개수 -> BFS의 실행 횟수
// 가장 큰 그림의 넓이 -> 각 BFS마다 큐에 들어갔다 나가는 좌표의 개수 중 최대값

#include <bits/stdc++.h>
#define xPos first
#define yPos second
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int n, m;
int paint[501][501]; // 0번 인덱스 사용 X
int cnt = 0; // 그림 개수
int paintSize = 1; // 해당 그림의 넓이
vector<int> paintSizes; // 모든 그림 넓이 저장
queue<pair<int, int>> q; // BFS에서 방문한 칸 저장할 큐

void BFS(int x, int y)
{
	while (!q.empty())
	{
		// 큐의 맨 앞에서 좌표 가져옴
		pair<int, int> currentPos = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			// 새로 이동할 좌표를 구함
			int newX = currentPos.xPos + dx[i];
			int newY = currentPos.yPos + dy[i];

			// 해당 좌표 범위 검사
			if (newX < 0 || newX > m || newY < 0 || newY > n) continue;

			if (paint[newY][newX])
			{
				// 해당 좌표 이동 방문 처리하고 큐에 추가
				paint[newY][newX] = 0;
				paintSize++;
				q.push(make_pair(newX, newY));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int inputVal;
			cin >> inputVal;
			paint[i][j] = inputVal;
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			paintSize = 1;

			if (paint[y][x]) // 1인 경우
			{
				cnt++; // 그림 개수 + 1
				paint[y][x] = 0; // 방문 처리
				q.push(make_pair(x, y)); // 현재 방문한 점 큐에 추가
				BFS(y, x);
				paintSizes.push_back(paintSize); // 해당 그림의 넓이 저장
			}
		}
	}

	cout << cnt << '\n';
	
	if (paintSizes.empty())
	{
		cout << 0;
	}
	else
	{
		cout << *max_element(paintSizes.begin(), paintSizes.end());
	}
}