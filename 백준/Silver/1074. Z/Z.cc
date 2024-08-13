#include <bits/stdc++.h>
using namespace std;

// 2^n * 2^n 배열에서 (r, c)를 몇 번째로 방문했는 지를 계산하는 함수
int Z(int n, int r, int c) {
	if (n == 0) return 0; // base condition

	// 배열을 4등분 했을 때, 각 사분면에 따라서 계산을 다르게 함
	// (r, c)의 위치에 따라 다르게 계산
	int half = 1 << (n-1); // 박스 절반 크기 -> 2^n의 절반(* 2^-1) -> 2^(n-1)과 같음
	if (r < half && c < half) return Z(n - 1, r, c); // 1사분면
	if (r < half && c >= half) return half * half + Z(n - 1, r, c - half); // 2사분면
	if (r >= half && c < half) return 2 * half * half + Z(n - 1, r - half, c); // 3사분면
	return 3 * half * half + Z(n - 1, r - half, c - half); // 4사분면
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
}