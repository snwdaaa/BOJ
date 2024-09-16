dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
q = [] # 큐
matrix = []
cnt = 0

def BFS():
    while (len(q) > 0):
        front = q.pop(0)

        for i in range(0, 4):
            newY = front[0] + dy[i]
            newX = front[1] + dx[i]

            if (newX < 0 or newX >= M or newY < 0 or newY >= N):
                continue
            if (not matrix[newY][newX] == 1):
                continue

            matrix[newY][newX] = 0
            q.append((newY,newX)) # (Y, X)          

T = int(input())

for i in range(0, 50):
    matrix.append([0 for _ in range(0, 50)]) # 인접 행렬

for tc in range(0, T):
    M, N, K = map(int, input().split()) # 가로, 세로, 위치 개수

    # 인접행렬 초기화
    for i in range(0, N):
        for j in range(0, M):
            matrix[i][j] = 0

    for _ in range(0, K):
        X, Y = map(int, input().split())
        matrix[Y][X] = 1

    for i in range(0, N):
        for j in range(0, M):
            if (matrix[i][j] == 1):
                cnt += 1
                matrix[i][j] = 0
                q.append((i,j)) # (Y, X)
                BFS()

    print(cnt)
    cnt = 0