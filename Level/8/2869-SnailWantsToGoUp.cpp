// V 미터인 나무
// 낮에 A 미터 올라감
// 밤에 B 미터 미끄러짐
// 정상에 올라간 후에는 미끄러지지 않음
// 올라가려면 며칠 걸림?

// O(1)에 풀어야 함 -> 반복문 사용 금지
#include <iostream>

int main()
{
    int A, B, V;
    std::cin >> A >> B >> V;

    int exactTop; // 정상에 도착하기 하루 전까지 움직인 거리에서 A만큼 올라가면 정확하게 정상인지 확인
    int passedDays; // 지난 날

    // A >= V인 경우에는 이미 정상 높이 이상이므로 미끄러지지 않음
    // => 하루 이동 거리가 A - B라는 가정을 할 수 없음
    if (A >= V) passedDays = 1; // 나무 높이보다 하루 이동 거리가 이상이면 하루만에 정상 찍음
    else // 하루 이동거리 A - B라 가정
    {
        // A만큼 올라갔을 때 정확히 정상이면 한 번 올라가면 바로 끝나므로 + 1일
        // 아니면 두 번 더 올라가야 하므로 + 2일
        exactTop = ((V - A) % (A - B) == 0) ? 1 : 2;
        // V - A => 정상에 도달하기 전 날까지 올라간 높이
        // 그 높이를 하루 이동거리 A - B로 나눈 것 => 정상에 도달하기 전까지 지난 날
        // 거기에 exactTop을 더해주면 됨
        passedDays = ((V - A) / (A - B)) + exactTop;
    }
    
    std::cout << passedDays << std::endl;

    return 0;
}