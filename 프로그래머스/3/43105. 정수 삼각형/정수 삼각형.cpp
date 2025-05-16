#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void CalcSum(vector<vector<int>>& triangle, vector<vector<int>>& sums, int maxDepth, int& maxVal) {
    for (int depth = 0; depth < maxDepth; depth++) {
        auto curLevel = triangle[depth];
        auto nextLevel = triangle[depth+1];
        for (int i = 0; i < curLevel.size(); i++) { // 각 depth의 모든 원소에 대해 sum 계산
            int leftIdx = (i == 0) ? 0 : i; // 각 레벨의 맨 왼쪽 or 오른쪽 원소면 i 그대로 사용
            int rightIdx = (i == curLevel.size()) ? curLevel.size() : i+1;
            if (sums[depth+1][leftIdx] < sums[depth][i] + nextLevel[leftIdx])
                sums[depth+1][leftIdx] = sums[depth][i] + nextLevel[leftIdx]; // 왼쪽 대각선 계산
            if (sums[depth+1][rightIdx] < sums[depth][i] + nextLevel[rightIdx])
                sums[depth+1][rightIdx] = sums[depth][i] + nextLevel[rightIdx]; // 오른쪽 대각선 계산

            // 마지막 레벨인 경우 최댓값 구하기
            if (depth == maxDepth-1) {
                maxVal = *max_element(sums[depth+1].begin(), sums[depth+1].end());
            }
        }    
    }
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> sums; // 각 경로의 합을 저장할 벡터
    int i = 0;
    for (vector<int> level : triangle) { // triangle과 똑같은 모양으로 0 채움
        sums.push_back(level);
        for (int len = 0; len < level.size(); len++) {
            sums[i][len] = 0;
        }
        i++;
    }
    sums[0][0] = triangle[0][0]; // 초기화
    CalcSum(triangle, sums, sums.size()-1, answer);

    return answer;
}