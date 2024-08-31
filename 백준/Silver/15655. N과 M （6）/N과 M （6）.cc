#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10001];
int nums[10001];
bool used[10001];
int maxNum = 0;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= maxNum; i++) {
		if (input[i] && !used[i]) {
			if (k >= 1 && nums[k - 1] > i) continue;
			nums[k] = i;
			used[i] = true;
			func(k + 1);
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int inputNum;
		cin >> inputNum;
		input[inputNum] = 1;
		if (maxNum < inputNum) maxNum = inputNum;
	}

	func(0);
}