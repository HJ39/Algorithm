N, M, x, y, K = map(int, input().split())

map_data = []
for _ in range(N):
    row = list(map(int, input().split()))
    map_data.append(row)

commands = list(map(int, input().split()))

# 주사위의 초기 상태
dice = [0] * 7
# 주사위의 현재 위치
pos = [x, y]

# 동, 서, 북, 남
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

for command in commands:
    nx = pos[0] + dx[command-1]
    ny = pos[1] + dy[command-1]

    # 지도를 벗어나는 경우 해당 명령 무시
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        continue

    # 동쪽으로 이동할 때
    if command == 1:
        dice[1], dice[3], dice[4], dice[6] = dice[4], dice[1], dice[6], dice[3]
    # 서쪽으로 이동할 때
    elif command == 2:
        dice[1], dice[3], dice[4], dice[6] = dice[3], dice[6], dice[1], dice[4]
    # 북쪽으로 이동할 때
    elif command == 3:
        dice[1], dice[2], dice[5], dice[6] = dice[5], dice[1], dice[6], dice[2]
    # 남쪽으로 이동할 때
    else:
        dice[1], dice[2], dice[5], dice[6] = dice[2], dice[6], dice[1], dice[5]

    # 이동한 칸의 숫자가 0인 경우
    if map_data[nx][ny] == 0:
        map_data[nx][ny] = dice[6]
    # 이동한 칸의 숫자가 0이 아닌 경우
    else:
        dice[6] = map_data[nx][ny]
        map_data[nx][ny] = 0

    pos = [nx, ny]
    print(dice[1])
