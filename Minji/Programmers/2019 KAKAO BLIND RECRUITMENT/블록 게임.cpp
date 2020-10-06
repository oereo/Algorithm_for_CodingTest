#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<int>> board) {
    int row = board.size();
    int col = board[0].size();
    bool removable[201] = {0};
    bool non_removable[201] = {0};
    int cnt = 0;
    unordered_map<int, int> dic;
    
    // 블록 판별
    for(int i = 0; i < row - 1; i++) {
        for(int j = 0; j < col; j++) {
            int now = board[i][j];
            if(now == 0 || removable[now] || non_removable[now]) continue;
            
            if(board[i+1][j] == now){
                if(i+2 < row && board[i+2][j] == now) {
                    if(j-1 >= 0 && board[i+2][j-1] == now){
                        dic[now] = 1;
                        removable[now] = 1;
                        cnt++;
                        continue;
                    } else if(j+1 < col && board[i+2][j+1] == now){
                        dic[now] = 2;
                        removable[now] = 1;
                        cnt++;
                        continue;
                    }
                }
                else if(j-2 >= 0 && board[i+1][j-1] == now && board[i+1][j-2] == now){
                    dic[now] = 3;
                    removable[now] = 1;
                    cnt++;
                    continue;
                } else if(j+2 < col && board[i+1][j+1] == now && board[i+1][j+2] == now){
                    dic[now] = 4;
                    removable[now] = 1;
                    cnt++;
                    continue;
                } else if(j-1 >= 0 && j+1 < col && board[i+1][j-1] == now && board[i+1][j+1] == now){
                    dic[now] = 5;
                    removable[now] = 1;
                    cnt++;
                    continue;
                }
            }
            non_removable[now] = 1;
        }        
    }
    
    // 제거 불가능한 블록 추가
    bool check[201] = {0};
    for(int i = 0; i < row; i++) {
        for(int j = col - 1; j >= 0; j--) {
            int now = board[i][j];
            if(check[now]) continue;
            check[now] = 1;
            switch(dic[now]){
                case 0:
                    break;
                case 1:
                    for(int a = i + 1; a >= 0 ; a--){
                        if(non_removable[board[a][j-1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    break;
                case 2:
                    for(int a = i + 1; a >= 0 ; a--){
                        if(non_removable[board[a][j+1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    break;
                case 3:
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j-1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    if(non_removable[now]) break;
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j-2]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    break;
                case 4:
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j+1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    if(non_removable[now]) break;
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j+2]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    break;
                case 5:
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j-1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    if(non_removable[now]) break;
                    for(int a = i; a >= 0 ; a--){
                        if(non_removable[board[a][j+1]]){
                            non_removable[now] = 1;
                            removable[now] = 0;
                            cnt--;
                            break;
                        }
                    }
                    break;
            }
        }
    }
    
    return cnt;
}