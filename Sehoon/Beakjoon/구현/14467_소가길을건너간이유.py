def main():
    cow_cross_nums = inputer_cow_cross()
    cow_cross_situations = inputer_cow_cross_situations(cow_cross_nums)
    cow_cross_cnt = get_how_many_cross_cow(cow_cross_situations, cow_cross_nums)
    print(cow_cross_cnt)


def get_how_many_cross_cow(cow_cross_situations:list, cow_cross_nums:int):
    result = [[2]*2 for _ in range(cow_cross_nums+1)]
    cnt = 0
    for situation in cow_cross_situations:
        if result[situation[0]][1] == 2 and result[situation[0]][1] != 1:
            result[situation[0]][0] = situation[1]
            result[situation[0]][1] = 1
        elif situation[1] != result[situation[0]][0] and result[situation[0]][1] ==1 and result[situation[0]][0] !=2:
            # print(situation[0])
            cnt +=1
            result[situation[0]][0] = situation[1]
        # print(result)
    return cnt


def inputer_cow_cross_situations(cow_cross_nums:int):
    cow_cross_situations = []
    for i in range(cow_cross_nums):
        cow_cross_situation = list(map(int, input().split()))
        cow_cross_situations.append(cow_cross_situation)
    return cow_cross_situations


def inputer_cow_cross():
    cow_cross_nums = int(input())
    return cow_cross_nums

main()