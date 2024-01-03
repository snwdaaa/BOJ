#include <iostream>
#include <vector>
using namespace std;

int GCD(int m, int n)
{
    if (n == 0) return m;
    return GCD(n, m%n);
}

int LCM(int m, int n)
{
    return m * n / GCD(m,n);
}

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(2));

    for(int i = 0; i < n; ++i)  // 입력
        cin >> vec[i][0] >> vec[i][1];

    for(int i = 0; i < n; ++i)  // 결과 출력
        cout << LCM(vec[i][0], vec[i][1]) << endl;

    return 0;
}