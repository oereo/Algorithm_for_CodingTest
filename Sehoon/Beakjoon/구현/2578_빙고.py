def main():
    bingo_map = inputer_bingo_map()
    question_bingo = inputer_question_bingo()
    result = get_bingo_finish_cnt(bingo_map, question_bingo)
    print(result)

def get_bingo_finish_cnt(bingo_map, question_bingo):
    line = 0
    flag = 0
    cnt = 0
    check = [0 for _ in range(12)]
    for i in range(5):
        if flag > 0:
            break
        for j in range(5):
            if flag > 0:
                break
            cnt +=1
            for x in range(5):
                if flag > 0:
                    break
                for y in range(5):
                    if flag > 0:
                        break
                    if question_bingo[i][j] == bingo_map[x][y]:
                        bingo_map[x][y] = 0
                        if x == y:
                            check[10] +=1
                        if (x + y) == 4:
                            check[11] +=1
                        check[x] +=1
                        check[y+5] +=1
                        for z in range(len(check)):      
                            if check[z] == 5:
                                line +=1
                                check[z] = 0
                                if line == 3:
                                    flag = cnt
                                    break
    # print(bingo_map)
    # print(question_bingo)
    # print(check)
    return flag

def inputer_bingo_map():
    bingo_map = []
    for i in range(5):
        bingo_map_row = list(map(int, input().split()))
        bingo_map.append(bingo_map_row)
    return bingo_map

def inputer_question_bingo():
    question_map = []
    for i in range(5):
        question_map_row = list(map(int, input().split()))
        question_map.append(question_map_row)
    return question_map

main()