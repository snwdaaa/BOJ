#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a%b);
}

int main(void)
{
    string input;
    int n, m;
    getline(cin, input);

    // :을 기준으로 그 앞 숫자는 n, 뒤 숫자는 m
    for(int i = 0; i < input.length(); ++i)
    {
        if(input[i] == ':')
        {
            n = stoi(input.substr(0, i));
            m = stoi(input.substr(i+1));
            break;
        }
    }

    // 두 수를 최대공약수로 나눔
    int gcd = GCD(n, m);
    cout << n / gcd << ":" << m / gcd << endl;

    return 0;
}