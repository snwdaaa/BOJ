#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

bool matrix[50][50] = { 0, }; // 인접 행렬
int t, m, n, k, x, y;

// 델타 탐색에 사용할 델타값
// 상, 하, 좌, 우 순서로 이동
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void DFS(int X, int Y)
{
	// 방문 처리
	matrix[Y][X] = 0;

	// 델타 탐색 후 1이 발견되면 발견된 곳으로 이동해서 다시 BFS 시행
	for (int i = 0; i < 4; i++)
	{
		// 배열 인덱스 조절
		int nextX = X + dx[i];
		int nextY = Y + dy[i];
		if (nextX >= m || nextX < 0 || nextY >= n || nextY < 0)
		{
			continue;
		}	

		if (matrix[nextY][nextX] == 1)
		{
			DFS(nextX, nextY);
		}
	}
}

int main()
{
	scanf("%d", &t);

	for (int tc = 0; tc < t; tc++)
	{
		scanf("%d %d %d", &m, &n, &k);	

		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			matrix[y][x] = 1;
		}

		// DFS 사용
		// DFS 시행 조건
		// 1. 해당 배추 그룹을 방문한 적 없음 -> 배열 이동 중 그 그룹에서 처음으로 탐색을 시작한 배추가 1
		// 2. 해당 영역에 배추가 있어야 함 -> 0인 경우에는 스킵
		// DFS를 시행하면 해당 배추를 0으로 만들어 방문 처리를 한 뒤, 델타 탐색을 통해 이동할 곳을 정한 후 또 그곳으로 이동해 DFS 시행 -> 그 배추 그룹의 모든 배추를 하나씩 방문하면서 0으로 만듦
		// 이렇게 되면 배추 그룹의 개수는 처음 DFS가 시작되는 부분에서 하나씩 세주면 구할 수 있음
		int count = 0; // 배추 그룹 카운트
		for (int i = 0; i < n; i++) // y
		{
			for (int j = 0; j < m; j++) // x
			{
				if (matrix[i][j] == 1)
				{
					count++;
					DFS(j, i);
				}
			}
		}

		printf("%d\n", count);
	}
}