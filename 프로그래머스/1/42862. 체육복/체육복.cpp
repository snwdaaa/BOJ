#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // lost와 reserve 오름차순으로 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // lost와 reserve에 모두 있는 중복 학생 제거
    for (auto it1 = lost.begin(); it1 != lost.end();) {
        auto it2 = find(reserve.begin(), reserve.end(), *it1); // lost와 같은 원소 찾기
        if (it2 != reserve.end()) { // 찾았으면 공통 원소 삭제
            reserve.erase(it2);
            it1 = lost.erase(it1); // 삭제 후 erase의 리턴 값으로 다음 원소로 이동 -> 이터레이터 무효화 해결
        }
        else
            ++it1;
    }
    
    // 리턴 값을 n - lost에 있는 학생 수로 설정
    answer = n - lost.size();
    
    // reserve에 있는 각 학생마다 앞뒤로 빌려줄 수 있는 학생 수를 계산
    int borrow[32] = {0, }; // 1 or 30인 경우 0 or 31을 참조할 수 있으므로 넉넉하게 잡음. 1-based index로 사용
    vector<int> prior1; // 빌려줄 수 있는 학생 수가 1인 학생
    vector<int> prior2; // 빌려줄 수 있는 학생 수가 2인 학생
    for (auto it = reserve.begin(); it != reserve.end();) {
        auto frontIt = find(lost.begin(), lost.end(), *it - 1);
        auto backIt = find(lost.begin(), lost.end(), *it + 1);
        if (frontIt != lost.end())
            borrow[*it] += 1;
        if (backIt != lost.end())
            borrow[*it] += 1;
        
        // 빌려줄 수 있는 학생 수가 1인 경우 우선적으로 빌려준 후, 두 학생을 lost와 reserve에서 각각 제외한 후, 학생 수 + 1
        if (borrow[*it] == 1) {
            it = reserve.erase(it); // reserve에서 제거
            if (frontIt != lost.end())  // 앞의 학생에게 빌려주는 경우 
                lost.erase(frontIt); // lost에서 제거
            else  // 뒤의 학생에게 빌려주는 경우
                lost.erase(backIt);
            answer++;
        }
        else if (borrow[*it] == 2) // 두 개인 경우 앞 학생에게 빌려줘버림
        {
            it = reserve.erase(it); // reserve에서 제거
            if (frontIt != lost.end())  // 앞의 학생에게 빌려주는 경우 
                lost.erase(frontIt); // lost에서 제거
            answer++;
        }
        else
            ++it;
    } 
    
    return answer;
}