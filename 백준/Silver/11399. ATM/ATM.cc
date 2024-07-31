#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int globalWaitTime = 0; // 누적 대기 시간
	vector<int> withdrawTime; // 각 사람의 인출 소요 시간 (Pi)
	int minWaitTimeSum = 0; // 인출하는데 필요한 시간 합 최소값 (결과값)

	// 각 사람의 인출 시간 입력
	for (int i = 0; i < n; i++)
	{
		int pi;
		scanf("%d", &pi);
		withdrawTime.push_back(pi);
	}

	// 인출하는 데 필요한 시간의 합의 최소값 구하기
	// 최소 시간부터 계속 더해나가면 최소합을 구할 수 있음 -> 그리디
	while (!withdrawTime.empty())
	{
		auto minTimeIter = min_element(withdrawTime.begin(), withdrawTime.end());
		const int& minTime = *minTimeIter; // 최소 대기 시간
		minWaitTimeSum += globalWaitTime + minTime; // 대기 시간의 합 = 지금까지의 누적 대기시간 + 나의 인출 시간
		globalWaitTime += minTime; // 누적 대기시간 증가
		withdrawTime.erase(minTimeIter); // 인출 끝났으면 삭제
	}

	printf("%d", minWaitTimeSum);
}