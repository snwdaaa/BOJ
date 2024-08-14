// visited 배열 사용 X

#include <bits/stdc++.h>
using namespace std;

int matrix[128][128];
int blueCnt = 0; // 파란 색종이 개수
int whiteCnt = 0; // 하얀 색종이 개수

void func(int n, int x, int y) {
	if (n == 0) return;

	int startColor = matrix[y][x];
	bool isSame = true;

	// 정사각형 모양의 각 구역이 n으로 꽉 찼는지 확인
	for (int i = 0; i < n; i++) { // o(n^2)
		for (int j = 0; j < n; j++) {
			if (matrix[y + i][x + j] != startColor) {
				isSame = false;
				break;
			}
		}
	}

	if (!isSame) {
		// 사분면 검사
		int half = n >> 1;
		func(half, x, y); // 1사분면
		func(half, x + half, y); // 2사분면
		func(half, x, y + half); // 3사분면
		func(half, x + half, y + half); // 4사분면
	}
	else {
		if (startColor == 0) whiteCnt++;
		else blueCnt++;
	}


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

	func(n, 0, 0); // amortized o(n^2)
	cout << whiteCnt << '\n' << blueCnt;
}