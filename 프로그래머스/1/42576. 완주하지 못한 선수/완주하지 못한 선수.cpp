#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 정렬 O(nlogn)
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    auto pIt = participant.begin();
    auto cIt = completion.begin();
    while (cIt != completion.end())
    {
        if (*pIt != *cIt) break;
        pIt++;
        cIt++;
    }
    answer = *pIt;
    
    return answer;
}