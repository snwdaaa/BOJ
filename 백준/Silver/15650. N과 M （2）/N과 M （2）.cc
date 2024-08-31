#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[9];
bool used[9];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == false) {
			if (k >= 1 && nums[k - 1] > i) continue; // 오름차순

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
	func(0);
}