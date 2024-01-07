// 나무의 개수 N, 그리고 N개의 거리 입력
// 같은 간격 -> 모든 나무 사이의 거리의 최대공약수
// 두 나무 사이에 같은 간격으로 나무를 심는 최소 개수 -> (두 나무 사이의 거리 / 최대공약수) -1
// (양쪽 끝의 나무가 무조건 존재하므로 1을 빼야 함)

#include <iostream>
#include <vector>
using namespace std;

int GCD(int, int);

int main(void)
{
    int N;                            // 미리 주어지는 나무의 개수
    cin >> N;
    vector<int> tree_pos(N);              // N개의 나무의 거리를 저장할 벡터
    for (int i = 0; i < N; ++i) 
        cin >> tree_pos[i];
    vector<int> tree_distance(N-1);   // 각 나무 사이의 거리를 저장할 벡터
    for (int i = 1; i < N; ++i) 
        tree_distance[i-1] = tree_pos[i] - tree_pos[i-1];

    // 3개 이상의 수의 최대공약수 구하기 -> for문 사용
    // ex) a b c 세 수의 최대공약수 => a 와 b의 최대공약수를 구한 후, 그 수와 c의 최대공약수를 구함
    int gcd = tree_distance[0];
    for (int i = 1; i < N-1; ++i)
        gcd = GCD(gcd, tree_distance[i]);

    int need_min = 0;       // 최소한으로 필요한 나무의 개수
    for (int i = 0; i < N-1; ++i) need_min += (tree_distance[i] / gcd) - 1;

    cout << need_min << endl;

    return 0;
}

int GCD(int m, int n)
{
    if(n == 0) return m;
    return GCD(n, m%n);
}