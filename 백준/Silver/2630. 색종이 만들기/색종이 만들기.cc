#include <bits/stdc++.h>
using namespace std;

int matrix[128][128];
int visited[128][128]; // 이미 처리한 경우 1로 바꿔 다시 계산 X
int blueCnt = 0; // 파란 색종이 개수
int whiteCnt = 0; // 하얀 색종이 개수

// 정사각형 모양의 각 구역이 n으로 꽉 찼는지 확인
bool CheckSquare(int color, pair<int, int> start, int size) { // o(n^2)
	bool isSame = true;
	int x = start.first;
	int y = start.second;

	for (int i = 0; i < size; i++) { // o(n^2)
		for (int j = 0; j < size; j++) {
			if (matrix[y + i][x + j] != color) isSame = false;
		}
	}

	if (isSame) {
		for (int i = 0; i < size; i++) { // o(n^2)
			for (int j = 0; j < size; j++) {
				visited[y + i][x + j] = 1; // 검사 완료 처리
			}
		}
	}

	return isSame;
}

void func(int n, pair<int, int> start) {
	int x = start.first;
	int y = start.second;
	int startColor = matrix[y][x];
	int half = n >> 1;

	if (visited[y][x] == 0) {
		if (n == 1) { // 한 칸만 남은 경우
			if (startColor == 0) whiteCnt++;
			else blueCnt++;
			return;
		}
		else if (CheckSquare(startColor, start, n)) { // 처리하지 않은 곳이면서 CheckSquare에서 모두 같은 색이라고 판별되면 그에 맞는 색깔 증가 // o(n^2)
			if (startColor == 0) whiteCnt++;
			else blueCnt++;
		}
	}
	else return;
	
	// 사분면 검사
	func(half, make_pair(x, y)); // 1사분면
	func(half, make_pair(x + half, y)); // 2사분면
	func(half, make_pair(x, y + half)); // 3사분면
	func(half, make_pair(x + half, y + half)); // 4사분면
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) { // o(n^2)
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	func(n, make_pair(0, 0)); // amortized o(n^2)
	cout << whiteCnt << '\n' << blueCnt;
}