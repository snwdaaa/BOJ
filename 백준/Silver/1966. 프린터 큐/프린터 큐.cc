#include <deque>
#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	// ( (우선순위, 문서번호), 출력 순서 )
	std::deque<std::pair<short, int>> queue;
	std::deque<std::pair<short, int>> result;
	int t; // 테스트 케이스
	std::cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		int n, m; // 문서 개수, 순서 찾을 문서
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			short priority;
			std::cin >> priority;
			queue.push_back(std::make_pair(priority, i));
		}

		short printOrder = 1; // 출력 순서
		while (!queue.empty())
		{
			// 중요도 확인
			const std::pair<short, int> frontDocu = queue.front(); // 큐의 맨 앞에 있는 원소
			const int& frontDocuNum = frontDocu.second; // 문서 번호
			const int& frontDocuPriority = frontDocu.first; // 문서 중요도

			queue.pop_front();

			// frontDocument보다 중요도가 높은 문서가 있는 지 확인
			int maxPriority = frontDocuPriority;
			for (auto iter = queue.begin(); iter != queue.end(); ++iter)
			{
				if ((*iter).first > maxPriority) // 큐를 한 번 돌면서 더 높은 중요도가 있는 지 확인
				{
					maxPriority = (*iter).first;
				}
			}
			
			if (frontDocuPriority < maxPriority) // 만약 더 높은 중요도가 있다면
			{
				queue.push_back(frontDocu); // 다시 큐의 뒤로 보냄
			}
			else
			{
				if (frontDocuNum == m) // 만약 출력한 문서가 찾는 문서라면
				{
					std::cout << printOrder << std::endl; // 출력 순서 출력
				}
				printOrder++;
			}
		}

		queue.clear(); // 큐 비우기
		printOrder = 1; // 출력 순서 재설정
	}
}