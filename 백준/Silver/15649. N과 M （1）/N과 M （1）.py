import sys
input = sys.stdin.readline

def func(k):
    if (k == m):
        for i in range (0, m):
            print(nums[i], end=' ')
        print()
        return
    # 1 ~ n 사이의 사용되지 않은 모든 수 확인
    for i in range(1, n+1):
        if (not isUsed[i]):
            nums[k] = i
            isUsed[i] = True
            func(k+1)
            isUsed[i] = False


n, m = map(int, input().split())
nums = []
isUsed = [False for _ in range(n+1)]

for i in range(0, n+1):
    nums.append(i)

func(0)