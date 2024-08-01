#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{	
	// n >= 3부터 반복해 계산 가능
	int dp[1001] = { -1, 1, 2, };
	
	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}


	printf("%d", dp[n]);
}