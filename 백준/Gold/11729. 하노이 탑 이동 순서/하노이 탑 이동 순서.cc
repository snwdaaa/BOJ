#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	hanoi(a, 6 - (a + b), n - 1); // n-1개의 원판을 기둥 a에서 목적지가 아닌 기둥 6-(a+b)로 옮김
	cout << a << ' ' << b << '\n'; // 제일 큰 원판을 옮김
	hanoi(6 - (a + b), b, n - 1); // n-1개의 원판을 6-(a+b) 기둥에서 목적지 기둥 b로 옮김
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	cout << (1 << num) - 1 << '\n'; // 옮긴 횟수
	hanoi(1, 3, num);
}