#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int board[21][21];

void getInput() {
    cin >> N;
    memset(board, -1, sizeof(board));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
}

void moveBoard(int direction) {
    int moved_board[21][21];
    int prev_num = -1;
    enum DIRECTION { UP, DOWN, LEFT, RIGHT };
    memset(moved_board, 0, sizeof(moved_board));

    switch(direction) {
    case DIRECTION::UP:
        for(int col = 0; col < N; col++) {
            int stacked_row = -1;
            prev_num = -1;
            for(int row = 0; row < N; row++) {
                if(board[row][col] == prev_num) {
                    moved_board[stacked_row][col] = prev_num * 2;
                    prev_num = -1;
                }
                else if(board[row][col] != 0) {
                    prev_num = board[row][col];
                    stacked_row++;
                    moved_board[stacked_row][col] = board[row][col];
                }
            }
        }
        break;
    case DIRECTION::DOWN:
        for(int col = 0; col < N; col++) {
            int stacked_row = N;
            prev_num = -1;
            for(int row = N-1; row >= 0; row--) {
                if(board[row][col] == prev_num) {
                    moved_board[stacked_row][col] = prev_num * 2;
                    prev_num = -1;
                }
                else if(board[row][col] != 0) {
                    prev_num = board[row][col];
                    stacked_row--;
                    moved_board[stacked_row][col] = board[row][col];
                }
                
            }
        }
        break;
    case DIRECTION::LEFT:
        for(int row = 0; row < N; row++) {
            int stacked_col = -1;
            prev_num = -1;
            for(int col = 0; col < N; col++) {
                if(board[row][col] == prev_num) {
                    moved_board[row][stacked_col] = prev_num * 2;
                    prev_num = -1;
                }
                else if(board[row][col] != 0) {
                    prev_num = board[row][col];
                    stacked_col++;
                    moved_board[row][stacked_col] = board[row][col];
                }
            }
        }
        break;
    case DIRECTION::RIGHT:
        for(int row = 0; row < N; row++) {
            int stacked_col = N;
            prev_num = -1;
            for(int col = N-1; col >= 0; col--) {
                if(board[row][col] == prev_num) {
                    moved_board[row][stacked_col] = prev_num * 2;
                    prev_num = -1;
                }
                else if(board[row][col] != 0) {
                    prev_num = board[row][col];
                    stacked_col--;
                    moved_board[row][stacked_col] = board[row][col];
                }
            }
        }
        break;
    }

    memcpy(board, moved_board, sizeof(board));
}

void pressCursor(int move_number, int direction, int& max_score) {
    int board_cpy[21][21];
    memcpy(board_cpy, board, sizeof(board));
    moveBoard(direction);

    if(move_number == 5) {
        int max = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] > max) {
                    max = board[i][j];
                }
            }
        }

        if(max > max_score) {
            max_score = max;
        }
    }
    else {
        for(int dir=0; dir<4; dir++) {
            pressCursor(move_number+1, dir, max_score);
        }
    }

    memcpy(board, board_cpy, sizeof(board));
}

void solution() {
    int ans = 0;
    for(int dir=0; dir<4; dir++) {
        pressCursor(1, dir, ans);
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}