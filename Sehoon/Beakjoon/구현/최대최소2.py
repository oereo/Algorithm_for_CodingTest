def main():
    case_num = case_num_inputer()

    for i in range(case_num):
        numbers_num = case_num_inputer()
        numbers = list(map(int, input().split()))
        max_number = get_max_number(numbers)
        min_number = get_min_number(numbers)
        print(min_number, max_number)


def get_max_number(numbers:list):
    return max(numbers)


def get_min_number(numbers:list):
    return min(numbers)


def case_num_inputer():
    return int(input())


main()