// 첫째 줄: 영수증에 적힌 총 금액
// 둘째 줄: 물건의 종류의 수 N
// 이후 N개의 줄: 각 물건의 가격 a와 개수 b
// 구매한 물건의 가격과 개수로 계산한 총 금액이 영수증에 적힌
// 총 금액과 일치하면 Yes, 아니면 No 출력

#include <iostream>
#include <vector>

struct GoodsInfo
{
    int price;  // 물건의 가격
    int count;  // 물건의 개수
};

int main(void)
{
    using namespace std;
    int N;  // 물건의 종류의 수
    int sum_receipt;    // 영수증에 적힌 총 금액
    int sum_calc = 0;   // 가격과 개수로 계산한 총 금액
    cin >> sum_receipt >> N;
    GoodsInfo* goods = new GoodsInfo[N];    // 동적 구조체 생성
    for (int i = 0; i < N; ++i)
    {
        cin >> goods[i].price >> goods[i].count;    // N개 상품의 가격과 개수 입력
        sum_calc += goods[i].price * goods[i].count;    // 상품 가격 합계 계산
    }

    if (sum_receipt == sum_calc) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}