BULB_STATE_COMMAND_1 = 1
BULB_STATE_COMMAND_2 = 2
BULB_STATE_COMMAND_3 = 3
BULB_STATE_COMMAND_4 = 4
TURN_ON = 1
TURN_OFF = 0

def main():
    bulb_size ,bulb_state_size = map(int, input().split())
    bulb = get_initial_bulb()
    bulb_state_commands = inputer(bulb_state_size)
    final_bulb_state = get_final_bulb_state(bulb_state_commands, bulb)
    final_bulb_state_printer(final_bulb_state)

def final_bulb_state_printer(final_bulb_state):
    for bulb_state in final_bulb_state:
        print(bulb_state, "", end='')

def get_initial_bulb():
    return list(map(int, input().split()))

def get_final_bulb_state(bulb_state_commands:list, bulb:list):
    for bulb_state in bulb_state_commands:
        if bulb_state[0] == BULB_STATE_COMMAND_1:
            bulb[bulb_state[1]-1] = bulb_state[2]
        if bulb_state[0] == BULB_STATE_COMMAND_2:
            for i in range(bulb_state[1]-1, bulb_state[2]):
                if bulb[i] == TURN_ON:
                    bulb[i] = TURN_OFF
                elif bulb[i] == TURN_OFF:
                    bulb[i] = TURN_ON
        if bulb_state[0] == BULB_STATE_COMMAND_3:
            bulb[bulb_state[1]-1:bulb_state[2]] = [TURN_OFF]*(bulb_state[2] - bulb_state[1]+1)
        if bulb_state[0] == BULB_STATE_COMMAND_4:
            bulb[bulb_state[1]-1:bulb_state[2]] = [TURN_ON]*(bulb_state[2] - bulb_state[1]+1)
    return bulb

def inputer(bulb_state_size:int):
    bulb_state_commands = []
    for _ in range(bulb_state_size):
        bulb_state_commands.append(list(map(int, input().split())))
    return bulb_state_commands


main()