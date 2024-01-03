#include <iostream>
#include <vector>

int main(void)
{
    using namespace std;
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) cin >> vec[i];
    int num;
    cin >> num;
    int count = 0;
    for(int i = 0; i < N; ++i) if(vec[i] == num) count++;
    cout << count << endl;
    return 0;
}