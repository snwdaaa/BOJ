#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> nameCnt;
    
    // O(n)
    for (auto it = participant.begin(); it != participant.end(); it++)
        nameCnt[*it]++;
    
    // O(n)
    for (auto it = completion.begin(); it != completion.end(); it++)
        nameCnt[*it]--;
    
    // O(n)
    for (auto it = nameCnt.begin(); it != nameCnt.end(); it++)
    {
        if (it->second == 1)
            answer = it->first;
    }
    
    return answer;
}