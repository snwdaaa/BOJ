#include <bits/stdc++.h>
using namespace std;

char matrix[4096][4096];
vector<char> result;

void compress(int n, int x, int y) {
	if (n == 1) {
		result.push_back(matrix[y][x]);
		return;
	}

	// 배열 전체 검사
	bool isSame = true;
	char startColor = matrix[y][x];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (startColor != matrix[y + i][x + j]) { // 다른게 하나라도 나오면 영상을 한 번 더 나눠야 함
				isSame = false;
				break;
			}		
		}
		if (!isSame) break;
	}

	if (!isSame) {
		if (n == 2) { // 2x2에서도 0과 1이 섞여있으면 압축하지 않고 그대로 저장
			result.push_back('(');
			result.push_back(matrix[y][x]);
			result.push_back(matrix[y][x + 1]);
			result.push_back(matrix[y + 1][x]);
			result.push_back(matrix[y + 1][x + 1]);
			result.push_back(')');
			return;
		}
		else { // 영상 나누기
			int half = n >> 1;
			result.push_back('(');
			compress(half, x, y);
			compress(half, x + half, y);
			compress(half, x, y + half);
			compress(half, x + half, y + half);
			result.push_back(')');
		}
	}
	else {
		result.push_back(startColor);
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore(); // 버퍼 개행문자 삭제

	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);

		for (int j = 0; j < n; j++) {
			matrix[i][j] = line.at(j);
		}
	}

	compress(n, 0, 0);

	for (char& ch : result) {
		cout << ch;
	}
}