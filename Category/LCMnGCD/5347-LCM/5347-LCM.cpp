#include <iostream>
#include <vector>
using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0) return a;
    return GCD(b, a%b);
}

long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}

int main(void)
{
    int n;
    long long a, b;
    cin >> n;
    vector<vector<long long>> vec(n, vector<long long>(2));

    for (int i = 0; i < n; ++i) cin >> vec[i][0] >> vec[i][1];       // 입력
    for (int i = 0; i < n; ++i) cout << LCM(vec[i][0], vec[i][1]) << endl;   // 출력

    return 0;
}