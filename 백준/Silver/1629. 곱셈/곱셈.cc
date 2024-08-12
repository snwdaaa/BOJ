#include <bits/stdc++.h>
using namespace std;

// b가 짝수인 경우
// a^b mod c = {(a^(b/2) mod c) * (a^(b/2) mod c)} mod c
// a^(b/2) mod c = {(a^(b/4) mod c) * (a^(b/4) mod c)} mod c
// a^(b/4) mod c = {(a^(b/8) mod c) * (a^(b/8) mod c)} mod c
// ...
// a^2 mod c = {(a mod c) * (a mod c)} mod c
// a mod c => 바로 구할 수 있음 (b=1일때)

// b가 홀수인 경우
// a^b mod c = (a * a^(b-1)) mod c  (b-1은 짝수)
//           = {(a mod c) * (a^(b-1) mod c)} mod c

long long CalcPow(long long a, long long b, long long c) {
	if (b == 1) { // base condition
		return a % c; // a mod c 반환
	}

	long long val = CalcPow(a, b / 2, c); // O(log b)
	val = (val * val) % c; // val은 기본적으로 b가 짝수일때만 생각

	if (b % 2 == 0) {
		return val;
	}
	else {
		return ((a % c) * val) % c; // {(a mod c) * (a^(b-1) mod c)} mod c
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << CalcPow(a, b, c);
}