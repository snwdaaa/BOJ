#include <bits/stdc++.h>
using namespace std;

int N;
int matrix[2187][2187];
int numCount[3] = { 0, 0, 0 }; // -1, 0, 1의 개수

// 한 변의 길이 n, 시작 위치 (x, y)
void recur(int n, int x, int y) {
	if (n < 1) return; // base condition

	// NxN 배열이 모두 같은 수인지 확인
	int startNum = matrix[y][x];
	bool isSame = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[y + i][x + j] != startNum) { // 다른 수가 하나라도 있으면
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	// 모두 같은 수인 경우
	if (isSame) {
		numCount[startNum + 1] += 1; // startNum은 -1 ~ 1이므로 +1을 더하면 인덱스 범위가 됨
	}
	else { // 다른 수가 하나라도 있으면 종이를 같은 크기의 9개로 자름
		int trisector = n / 3;
		recur(trisector, x, y);
		recur(trisector, x + trisector, y);
		recur(trisector, x + 2 * trisector, y);
		recur(trisector, x, y + trisector);
		recur(trisector, x + trisector, y + trisector);
		recur(trisector, x + 2 * trisector, y + trisector);
		recur(trisector, x, y + 2 * trisector);
		recur(trisector, x + trisector, y + 2 * trisector);
		recur(trisector, x + 2 * trisector, y + 2 * trisector);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j]; // -1, 0, 1 입력
		}
	}

	recur(N, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << numCount[i] << '\n';
	}
}