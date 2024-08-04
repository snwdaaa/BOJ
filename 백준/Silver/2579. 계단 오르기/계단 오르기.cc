#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; // 계단 개수
	scanf("%d", &n);

	vector<int> s; // 각 계단의 점수
	s.push_back(0); // 0번 인덱스 사용 X
	for (int i = 0; i < n; i++)
	{
		int inputScore;
		scanf("%d", &inputScore);
		s.push_back(inputScore);
	}

	// 계단을 한 칸만 올라가는 경우 아래 식 사용하면 인덱스 오류 발생
	if (n == 1)
	{
		printf("%d", s.at(1));
		return 0;
	}

	// dp[i][j]: j개의 계단을 연속으로 밟고 i번째 계단에 올랐을 때의 최대 점수 (i: 1 ~ 300, j: 1~2)
	int dp[301][2]; // 0번 인덱스 사용 X
	// 초기값 설정
	dp[1][1] = s.at(1);
	dp[1][2] = 0; // 불가능함
	dp[2][1] = s.at(2);
	dp[2][2] = s.at(1) + s.at(2);

	for (int i = 3; i <= n; i++)
	{
		// dp[i][1] 계산
		// 연속해서 1개의 계단을 밟고 i번째 계단에 올라섬 => i-2번째 계단에서 바로 올라옴
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s.at(i); // i-2 번째 계단에서 한 개 / 두 개 연속으로 올라온 점수 중 더 큰 값을 선택

		// dp[i][2] 계산
		// 연속해서 2개의 계단을 밟고 i번째 계단에 올라섬 => i-2, i-1, i 순서로 올라옴
		// 이때, i-1에 올라왔을 때는 연속해서 한 개의 계단을 올라온 상태여야 함 -> 두 개인 상태면 i번째에 올라왔을 때 연속해서 3개의 계단을 올라온 것이기 때문
		dp[i][2] = dp[i - 1][1] + s.at(i); // i-1번째 계단에서 연속해서 한 개의 계단을 올라온 경우라면 [i-1][1]
	}

	printf("%d", max(dp[n][1], dp[n][2])); // 마지막 계단의 값 중 한 칸 / 두 칸 올라온 점수 중 더 큰 값 출력
}