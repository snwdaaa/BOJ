#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long Fibo(int);

int main(void)
{
    int num;
    cin >> num;
    memo.assign(num+1, -1);
    cout << Fibo(num) << endl;
    
    return 0;
}

long long Fibo(int N)
{
    if (N == 0) return 0;
    else if (N == 1) return 1;

    if (memo[N] != -1) return memo[N];
    return memo[N] = Fibo(N-1) + Fibo(N-2);
}