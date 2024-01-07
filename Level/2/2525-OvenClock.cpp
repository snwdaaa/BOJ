// 현재_시(0~23) 현재_분(0~59)
// 소요_분(0~1000)
// => 소요_분이 지난 시 , 분 출력

#include <iostream>

int main(void)
{
    unsigned int now_hour, now_min, need_min;
    std::cin >> now_hour;
    std::cin >> now_min;
    std::cin >> need_min;

    now_min += need_min;

    // 시, 분, 분 범위 계산
    if(now_min >= 60) // 60분 이상 -> 시간 넘기기
    {
        now_hour += (now_min / 60);
        now_min -= (now_min / 60) * 60;
    }

    // 시 범위 계산
    if(now_hour >= 24)
    {
        now_hour = now_hour - 24;
    }

    std::cout << now_hour << " " << now_min << std::endl;

    return 0;
}