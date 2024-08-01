#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	// 1, 2, 3을 1,2,3으로 나타내는 방법의 수는 각각 1, 2, 4
	int dp[12] = { -1, 1, 2, 4, }; // 0번 인덱스 사용 X

	// 4 ~ 11의 방법의 수를 미리 구함
	for (int i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int tc = 0; tc < T; tc++)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}