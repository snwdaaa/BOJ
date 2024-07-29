#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 전역 변수
int k, n;
vector<long long> cableLength; // 케이블 k개의 길이를 받을 벡터
set<long long> result;

// mid 길이로 몇 개의 길이가 같은 케이블을 만들 수 있는 지 확인
int CheckCableCount(long long mid)
{
    int count = 0;

    for (const long long& elem : cableLength)
    {
        count += elem / mid;
    }

    return count;
}

void BinarySearch(long long left, long long right)
{
    if (left > right) // 종료 조건
    {
        return;
    }

    long long mid = (left + right) / 2;
    int cableCount = CheckCableCount(mid); // O(K) -> 10,000번

    // 정확히 n개의 케이블을 만들 수 있거나 더 많이 만들 수 있는 길이를 셋에 저장
    if (cableCount >= n)
    {
        result.insert(mid);
        BinarySearch(mid + 1, right); // 최대 길이를 구해야 하므로 가능한 한 계속 길이를 늘림
    }
    else
    {
        BinarySearch(left, mid - 1); // 만들어야 할 케이블보다 적으면 길이를 길게 잡은 것이므로 길이를 줄여서 다시 체크
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        long long length;
        cin >> length;
        cableLength.push_back(length);
    }

    // 둘 다 1인 경우 들어온 값 바로 출력
    if (k == 1 && n == 1)
    {
        cout << cableLength.back();
        return 0;
    }

    BinarySearch(1, *max_element(cableLength.begin(), cableLength.end()));

    cout << *max_element(result.begin(), result.end());
}