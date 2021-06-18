EIGHT = 8

def main(octa_num):
    octa_num_length = len(octa_num)
    decimal_num = get_decimal_num(octa_num, octa_num_length)
    binary_num = get_binary_num(decimal_num)
    return binary_num

def get_decimal_num(octa_num, octa_num_length):
    decimal_num = 0
    for index, value in enumerate(octa_num):
        decimal_num += int(value) * pow(EIGHT, octa_num_length-int(index)-1) 
    return decimal_num

def get_binary_num(decimal_num):
    binary_num = ""
    while decimal_num >=1:
        if decimal_num % 2 == 1:
            binary_num = binary_num + "1"
        elif decimal_num %2 == 0:
            binary_num = binary_num + "0"
        decimal_num = decimal_num//2

    return binary_num[::-1]

octa_num = input()
print(main(octa_num))