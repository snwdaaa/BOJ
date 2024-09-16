N, X = map(int, input().split())
A = list(map(int, input().split())) # 리스트

for num in A:
    if (num < X):
        print(num, end=' ')