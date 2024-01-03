#include <iostream>
using namespace std;

long long GCD(long long m, long long n)
{
    if (n==0) return m;
    return GCD(n, m%n);
}

long long LCM(long long m, long long n)
{
    return m * n / GCD(m, n);
}

int main(void)
{
    long long a, b;
    cin >> a >> b;
    cout << LCM(a, b) << endl;

    return 0;
}