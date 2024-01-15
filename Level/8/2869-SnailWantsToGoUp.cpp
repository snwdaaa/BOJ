// V 미터인 나무
// 낮에 A 미터 올라감
// 밤에 B 미터 미끄러짐
// 올라가려면 며칠 걸림?

#include <iostream>

int main()
{
    int A, B, V;
    std::cin >> A >> B >> V;

    int climbedDist = 0; // 지상으로부터 올라간 거리
    int passedDays = 0;
    while (climbedDist < V)
    {
        // 낮
        climbedDist += A;

        // 밤
        if (climbedDist < V) climbedDist -= B; // 정상에 도달하지 않은 경우에만 미끄러지지 않게
        if (climbedDist < 0) climbedDist = 0; // 음수로 내려가지 않게

        // 다음날
        passedDays++;
    }

    std::cout << passedDays << std::endl;

    return 0;
}