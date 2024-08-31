#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[9]; // 길이가 최대 M인 수열
int used[9]; // 특정 수 사용 여부 저장

void func(int k) {
	if (k == m) { // 길이 m개 되면
		for (int i = 0; i < m; i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';
		return;
	}

	// 1 ~ n 사이의 사용되지 않은 모든 수를 확인
	for (int i = 1; i <= n; i++) {
		if (used[i] == false) { // 사용 X 발견
			nums[k] = i; // 수열의 k번째 수는 i
			used[i] = true; // 사용 처리
			func(k + 1); // 다음 자리 수 결정
			used[i] = false; // nums[k]가 i일때 나머지 모든 수를 결정했으면 i도 다시 사용 x로 변경
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}