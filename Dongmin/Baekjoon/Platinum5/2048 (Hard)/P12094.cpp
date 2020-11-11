#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int N, init_max;
int board[21][21];

void getInput() {
    cin >> N;
    memset(board, -1, sizeof(board));
    int max=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] > max) max = board[i][j];
        }
    }
    init_max = max;
}

void moveBoard(int direction, int prev_max, int& now_max) {
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
                    if(prev_num == prev_max) now_max = moved_board[stacked_row][col];
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
                    if(prev_num == prev_max) now_max = moved_board[stacked_row][col];
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
                    if(prev_num == prev_max) now_max = moved_board[row][stacked_col];
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
                    if(prev_num == prev_max) now_max = moved_board[row][stacked_col];
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

void pressCursor(int move_number, int direction, int prev_max_score, int& max_score) {
    int board_cpy[21][21];
    int now_max = prev_max_score;
    memcpy(board_cpy, board, sizeof(board));
    moveBoard(direction, prev_max_score, now_max);

    int remained_move = 10 - move_number;
    int possible_max = now_max * pow(2, remained_move);
    if(possible_max > max_score) {
        if(move_number == 10) {
            if(now_max > max_score) {
                max_score = now_max;
            }
        }
        else {
            for(int dir=0; dir<4; dir++) {
                pressCursor(move_number+1, dir, now_max, max_score);
            }
        }
    }

    memcpy(board, board_cpy, sizeof(board));
}

void solution() {
    int ans = 0;
    for(int dir=0; dir<4; dir++) {
        pressCursor(1, dir, init_max, ans);
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}