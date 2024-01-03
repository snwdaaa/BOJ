#include <iostream>
#include <vector>

int main(void)
{
    using namespace std;
    vector<int> submissionList(28);
    for(int i = 0; i < 28; ++i) cin >> submissionList[i];

    for(int i = 1; i <= 30; ++i)
    {
        bool isExist = false;
        for (int j = 0; j < 28; ++j)
        {
            if(submissionList[j] == i) isExist = true;
        }
        if (!isExist) cout << i << endl;
    }
    return 0;
}