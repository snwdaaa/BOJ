// 첫 줄에 케이스 개수 N 입력
// 각 줄마다 각 케이스를 입력, 그리고 모든 원소들을 두 쌍으로 만들었을 때 최대공약수가 가장 큰 수 출력
// ex) 10 20 30 40 => 20

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int GCD(int, int);

int main(void)
{
    int N;
    cin >> N;
    vector<int>* vec = new vector<int>[N];    // 정수를 담는 벡터
    cin.get();
    for (int i = 0; i < N; ++i)
    {
        string str;
        getline(cin, str);
        stringstream ss;
        ss.str(str);
        
        // 각 라인에서 숫자들을 벡터로 집어넣음
        int num;
        while (ss >> num)
        {
            vec[i].push_back(num);
        }
    }

    // 한 줄에 있는 여러 수를 두 쌍을 묶은 후, 최대공약수를 구함
    // 최대공약수를 계속 기억해가면서 가장 큰 최대공약수를 구한 후
    // 마지막에 출력

    for (int i = 0; i < N; ++i)
    {
        int maxGCD = 0;
        for (int j = 0; j < vec[i].size(); ++j)
        {
            for (int k = j+1; k < vec[i].size(); ++k)
            {
                if (GCD(vec[i][j], vec[i][k]) > maxGCD) maxGCD = GCD(vec[i][j], vec[i][k]);
            }
        }
        cout << maxGCD << endl;
    }

    return 0;
}

int GCD(int m, int n)
{
    if (n == 0) return m;
    return GCD(n, m%n);
}