#include <iostream>
using namespace std;

// 최대공약수
int GCD(int m, int n)
{
    if (n == 0) return m;

    return GCD(n, m%n);
}

// 최소공배수
// LCM(m,n) = m*n / GCD(m,n)
// 두 수의 최소공배수는 두 수를 곱한 수를 두 수의 최대공약수로 나눔
int LCM(int m, int n)
{
    return m * n / GCD (m, n);
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    cout << GCD(a, b) << endl;
    cout << LCM(a, b) << endl;

    return 0;
}