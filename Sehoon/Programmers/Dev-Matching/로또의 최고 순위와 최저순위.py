from enum import Enum, unique

ZERO_NUMBER = 0
LOTTO_SIZE = 6

@unique
class LottoStatisticMatchingNumber(Enum):
    ZERO_MATCHED = (6, 0)
    ONE_MATCHED = (6, 1)
    TWO_MATCHED = (5, 2)
    THREE_MATCHED = (4, 3)
    FOUR_MATCHED = (3, 4)
    FIVE_MATCHED = (2, 5)
    SIX_MATCHED = (1, 6)

    def __init__(self, rank, matched_count):
        self.rank = rank
        self.matched_count = matched_count


def solution(lottos, win_nums):
    zero_numbers = lottos.count(ZERO_NUMBER)
    correct_lottos_cnt = get_correct_lottos(lottos, win_nums)
    
    answer = []
    answer.append(get_rank(correct_lottos_cnt + zero_numbers))
    answer.append(get_rank(correct_lottos_cnt)),
    
    return answer


def get_correct_lottos(lottos, win_nums):
    correct_cnt = 0
    for i in range(LOTTO_SIZE):
        if is_correct(lottos[i], win_nums):
            correct_cnt = correct_cnt + 1
    return correct_cnt
    
def is_correct(lotto_num:int, win_num:list) -> bool:
    if lotto_num in win_num:
        return True
    return False


def get_rank(correct_num) -> int:
    for lotto_matched_index in LottoStatisticMatchingNumber:
        if correct_num == lotto_matched_index.matched_count:
            return lotto_matched_index.rank