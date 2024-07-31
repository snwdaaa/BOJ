#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	vector<int> inputSeq; // 입력받은 배열
	int n;
	cin >> n;

	// 수열 값 입력
	for (int i = 0; i < n; i++)
	{
		int inputNum;
		cin >> inputNum;
		inputSeq.push_back(inputNum);
	}

	// 한 개의 수만 있는 경우 무조건 수열을 만들 수 있음
	if (n == 1)
	{
		cout << "+" << '\n' << "-";
		return 0;
	}

	auto progress = inputSeq.begin(); // 수열을 어디까지 확인했는지 나타내는 이터레이터

	vector<int> tempStack; // 임시 벡터
	vector<int> result; // 1 ~ n 사이의 수로 만든 수열을 저장할 벡터
	vector<char> operationLog; // 연산 기록

	// tempStack에 집어 넣을 1 ~ n 사이의 수
	int num = 1;

	// 입력 수열 전체 순회
	while (progress != inputSeq.end())
	{
		// 1부터 시작해 n까지 오름차순으로 tempStack에 저장
		if (!tempStack.empty())
		{
			if (tempStack.back() == *progress) // 만약 스택의 맨 위에 있는 값이 현재 progress가 가리키는 값과 같다면
			{
				result.push_back(tempStack.back()); // 스택 맨 위 값을 결과 벡터에 넣음
				tempStack.pop_back(); // tempStack의 옮긴 값 삭제
				operationLog.push_back('-');
				progress++; // 이터레이터 한 칸 전진
				continue; // 검사 한 번 더 하기 위해 continue
			}
			else if (tempStack.back() > *progress) // progress가 가리키는 값이 현재 tempStack에 있는 마지막 값보다 작다면 해당 수열을 만들 수 없음
			{
				cout << "NO" << '\n';
				return 0;
			}
		}

		tempStack.push_back(num);
		operationLog.push_back('+');

		if (num < n) // num == n이 되면 더 이상 증가하는 것을 멈추고 스택에 남아있는 숫자와 progress를 비교하는 작업만 함
		{
			num++;
		}
	}

	
	if (!tempStack.empty()) // 스택에 수가 남아있으면
	{
		cout << "NO" << '\n';
	}
	else if (inputSeq == result) // 입력 수열과 결과 수열이 같으면
	{
		for (const char& elem : operationLog)
		{
			cout << elem << '\n';
		}
	}
	else
	{
		cout << "NO" << '\n';
	}
}