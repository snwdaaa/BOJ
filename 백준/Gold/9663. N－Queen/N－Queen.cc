#include <bits/stdc++.h>
using namespace std;

int N;
int caseCount = 0;
bool isUsed_vertical[40];
bool isUsed_leftDown_rightUp[40];
bool isUsed_leftUp_rightDown[40];


// k번째 행에 말 배치하기
// (행, 열) -> (k, i)
void PlaceQueen(int k)
{
	if (k == N)
	{
		caseCount++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isUsed_vertical[i] || isUsed_leftDown_rightUp[k + i] || isUsed_leftUp_rightDown[k - i + (N - 1)]) continue;

		isUsed_vertical[i] = true;
		isUsed_leftDown_rightUp[k + i] = true;
		isUsed_leftUp_rightDown[k - i + (N - 1)] = true;
		PlaceQueen(k + 1);
		isUsed_vertical[i] = false;
		isUsed_leftDown_rightUp[k + i] = false;
		isUsed_leftUp_rightDown[k - i + (N - 1)] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	PlaceQueen(0);

	cout << caseCount;
}