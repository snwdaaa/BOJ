#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[7];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		nums[k] = i;
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}