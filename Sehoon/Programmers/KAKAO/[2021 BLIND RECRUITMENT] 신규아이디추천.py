import re
import itertools
from itertools import groupby

NULL_CHECK_CHAR = "a"


def solution(new_id):
    init_id = new_id
    
    first_step_id = get_first_step_id(init_id)
    second_step_id = get_second_step_id(first_step_id)
    third_step_id = get_third_step_id(second_step_id)
    fourth_step_id = get_fourth_step_id(third_step_id)
    fifth_step_id = get_fifth_step_id(fourth_step_id)
    sixth_step_id = get_sixth_step_id(fifth_step_id)
    seventh_step_id = get_seventh_step_id(sixth_step_id)
    answer = seventh_step_id
    return answer


def get_first_step_id(init_id: str):
    return init_id.lower()


def get_second_step_id(first_step_id:str):
    return re.sub(r"[^a-z0-9-_.]","", first_step_id)


def get_third_step_id(second_step_id:str):
    result = second_step_id[0]
    for i in range(1, len(second_step_id)):
        if second_step_id[i-1] != second_step_id[i]:
            result += second_step_id[i]
        else:
            if second_step_id[i] != ".":
                result += second_step_id[i]
    return result

def get_fourth_step_id(third_step_id:str):
    third_step_ids = list(third_step_id)
    if len(third_step_ids)>=1:
        if third_step_ids[0] == ".":
            print(third_step_ids[0])
            third_step_ids.pop(0)
    if len(third_step_ids)>=1:
        if third_step_ids[len(third_step_ids)-1] == ".":
            third_step_ids.pop(len(third_step_ids)-1)
    result = "".join(third_step_ids)
    return result


def get_fifth_step_id(fourth_step_id:str):
    if len(fourth_step_id) == 0:
        return NULL_CHECK_CHAR
    return fourth_step_id


def get_sixth_step_id(fifth_step_id:str):
    result = ""
    if len(fifth_step_id)>=16:
        result = fifth_step_id[0:15]
        if result[len(result)-1] == ".":
            result = result[:-1]
        return result
    return fifth_step_id


def get_seventh_step_id(sixth_step_id:str):
    sixth_step_id_length = len(sixth_step_id)
    if sixth_step_id_length <=2:
        sixth_step_id_final_char = sixth_step_id[sixth_step_id_length-1]
        for i in range(3-sixth_step_id_length):
            sixth_step_id += sixth_step_id_final_char
    return sixth_step_id