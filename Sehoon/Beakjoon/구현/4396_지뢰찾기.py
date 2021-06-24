
direction_x = [1, 0, -1, 0, 1, 1, -1, -1]
direction_y = [0, -1, 0 ,1, 1, -1, 1, -1]

def main(n):
    map1 = inputer_map1(n)
    map2 = inputer_map2(n)
    answer = [['.']*n for _ in range(n)]
    # print(map1)
    # print(map2)
    cnt = 0
    is_boom = False
    for i in range(n):
        for j in range(n):
            if map1[i][j] == "*" and map2[i][j] == "x":
                is_boom = True
            if map1[i][j] == '.' and map2[i][j] == "x":
                for k in range(8):
                    dx = i + direction_x[k]
                    dy = j + direction_y[k]
                    if dx>=0 and dy>=0 and dx<n and dy<n:
                        if map1[dx][dy] == "*":
                            cnt +=1
                answer[i][j] = cnt
                cnt = 0

    
    if is_boom is True:
        for i in range(n):
            for j in range(n):
                if map1[i][j] == "*":
                    answer[i][j] = "*"
            
    for i in range(n):
        for j in range(n):
            print(answer[i][j], end='')
        print()

def inputer_map1(n):
    map1 = []
    for i in range(n):
        row = list(input())
        map1.append(row)
    return map1

def inputer_map2(n):
    map2 = []
    for i in range(n):
        row = list(input())
        map2.append(row)
    return map2


n = int(input())

main(n)