#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
set<string> s;
set<string> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;

		auto p = s.find(name);
		if (p != s.end()) { // 이미 입력 받은 사람이면
			cnt++;
			result.insert(*p); // 결과 벡터에 이름 추가
		}
	}

	cout << cnt << '\n';
	for (auto& elem : result) {
		cout << elem << '\n';
	}
}