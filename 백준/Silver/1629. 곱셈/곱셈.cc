#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

// A^B % C는 (A^(B/2) % C) * (A^(B/2) % C)로 표현 가능
// A^(B/2) % C는 (A^(B/4) % C) * (A^(B/4) % C)로 표현 가능
// A^(B/4) % C는 (A^(B/8) % C) * (A^(B/8) % C)로 표현 가능
// ...
// A^2 % C는 (A % C) * (A % C)로 표현 가능
// A % C는 바로 구할 수 있음 (B=1인 경우). 여기까지 구했으면 다시 위로 올라가면서 다 제곱 해줌
// 이런식으로 가면 O(log B)로 계산 가능 (지수인 B가 계속 반으로 나누어지니까)
long long func(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}

	long long val = func(a, b / 2, c);
	val = (val * val) % c; // (A % C) * (A % C) = (A * A) % C

	if (b % 2 == 0) { 
		return val;
	}
	else {
		// b가 홀수일 때 a^b는 a^(b-1) * a.    (b-1)은 짝수
		// ex) A^3 % C = ((A % C) * (A % C)) * A = ((A * A) * A) % C
		return (val * a) % c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	cout << func(a, b, c);
}