def main(map_col_size, solution_num):
    snail_map = [[0]*map_col_size for _ in range(map_col_size)]
    result= map_col_size*map_col_size
    direction = 1
    dfs(0,0, result, map_col_size, snail_map, direction)
    printer_snail_map(snail_map)
    get_index_in_snail_map(snail_map, map_col_size, solution_num)

def printer_snail_map(snail_map):
    for row in snail_map:
        print('\n')
        for col in row:
            print(col, end=" ")

def get_index_in_snail_map(snail_map:list, map_col_size, solution_num):
    for i in range(map_col_size):
        print(i)
        for j in range(map_col_size):
            if snail_map[i][j] == solution_num:
                print(i+1, j+1)  

def dfs(x,y, result, n, graph, direction):
    # print("n", n)
    if x<0 or x>=n-1 or y<0 or y>=n-1 or graph[x][y] !=0:
        if direction == 1:
            direction = 2
        elif direction == 2:
            direction = 3
        elif direction == 3:
            direction = 4
        elif direction == 4:
            direction = 1
    print(x, y)
    print(direction)
        
    if direction == 1:
        graph[x][y]=result
        result-=1
        dfs(x+1,y, result, n, graph, direction)
    if direction == 2:
        graph[x][y]=result
        result-=1
        dfs(x,y+1, result, n, graph, direction)
    if direction == 3:
        graph[x][y]=result
        result-=1    
        dfs(x-1,y, result, n, graph, direction)
    if direction == 4:
        graph[x][y]=result
        result-=1
        dfs(x,y-1, result, n, graph, direction)
    return result
  

map_col_size = int(input())
solution_num = int(input())
main(map_col_size, solution_num)