# def main():
#     duck_quack = inputer_duck_quack()
#     print(duck_quack)
#     print(get_duck_num(duck_quack))

# def get_duck_num(duck_quack):
#     ducks = []
#     for duck_quack_char in duck_quack:
#         for duck in ducks:
#             if duck[-1] == 'q' and duck_quack_char == 'u':
#                 duck +=duck_quack_char
#             elif duck[-1] == 'u' and duck_quack_char == 'a':
#                 duck +=duck_quack_char
#             elif duck[-1] == 'a' and duck_quack_char == 'c':
#                 duck +=duck_quack_char
#             elif duck[-1] == 'c' and duck_quack_char == 'k':
#                 duck +=duck_quack_char
#             elif duck[-1] == 'k' and duck_quack_char == 'q':
#                 duck +=duck_quack_char    
#             else :
#                 temp = []
#                 temp.append(duck_quack_char)
#                 ducks.append(temp)
#     print(ducks)
#     return ducks   


# def inputer_duck_quack():
#     duck_quack = input()
#     return duck_quack

# main()