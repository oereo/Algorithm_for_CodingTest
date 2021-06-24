def main(initial_money, stock_plan):
    joonhyeon_money = get_joonhyeon_money(initial_money, stock_plan)
    seongmin_money = get_seongmin_money(initial_money, stock_plan)
    printer_winner(joonhyeon_money, seongmin_money)

def printer_winner(joonhyeon_money, seongmin_money):
    if joonhyeon_money > seongmin_money:
        print("BNP")
    elif joonhyeon_money < seongmin_money:
        print("TIMING")
    else:
        print("SAMESAME")

def get_joonhyeon_money(initial_money, stock_plan):
    stock_cnt = 0
    for stock in stock_plan:
        if initial_money>=stock:
            stock_cnt += initial_money // stock
            initial_money = initial_money - (stock_cnt * stock)
    return stock_cnt * stock_plan[len(stock_plan)-1] + initial_money


def get_seongmin_money(initial_money, stock_plan):
    increase_flag = 0
    decrease_flag = 0
    stock_cnt = 0

    for index, stock in enumerate(stock_plan):
        if index >=1 and stock > stock_plan[index-1]:
            increase_flag +=1
            decrease_flag = 0
        if index >=1 and stock < stock_plan[index-1]:
            decrease_flag +=1
            increase_flag = 0
        if increase_flag >= 3:
            initial_money = initial_money + stock_cnt * stock
            stock_cnt = 0
        if decrease_flag >= 3 and initial_money>=stock:
            purchase_stock_cnt = initial_money // stock
            stock_cnt += purchase_stock_cnt
            initial_money = initial_money - (purchase_stock_cnt * stock)
        # print(index, stock, increase_flag, decrease_flag, stock_cnt, initial_money )
    return stock_cnt * stock_plan[len(stock_plan)-1] + initial_money

initial_money = int(input())
stock_plan = list(map(int, input().split()))
main(initial_money, stock_plan)