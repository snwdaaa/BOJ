#include <bits/stdc++.h>
using namespace std;

int M, N;
int input[10001]; // 입력받은 수가 1
int nums[10]; // k번째 순서의 수 저장
bool isUsed[10001]; // 사용 중인 수는 1
int maxNum = -1;

// k번째 수를 정하는 함수
void func(int k)
{
	if (k == M) // 최대 길이와 선택한 수의 개수가 같아진 경우
	{
		for (int i = 0; i < M; i++)
		{
			cout << nums[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= maxNum; i++)
	{
		if (input[i] && nums[k-1] <= i)
		{
			nums[k] = i;
			isUsed[i] = true;
			func(k+1); // k + 1번째 숫자 결정
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int inputNum;
		cin >> inputNum;
		if (maxNum < inputNum) maxNum = inputNum;
		input[inputNum] = 1;
	}

	func(0);
}