#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row, col;
} Pos;
typedef struct Block {
    Pos pos;
    int type;
} Block;

int N;
vector<vector<int> > green_board, blue_board;
vector<int> green_top, blue_top;
vector<int> green_filled, blue_filled;
vector<Block> blocks;

void getInput() {
    cin >> N;
    blocks.assign(N, {{0,0}, 0});
    for(int i=0; i<N; i++) {
        cin >> blocks[i].type >> blocks[i].pos.row >> blocks[i].pos.col;
    }

    green_board.assign(6, vector<int>(4,0));
    blue_board.assign(6, vector<int>(4, 0));
    green_top.assign(4, 5);
    blue_top.assign(4, 5);
    green_filled.assign(6, 0);
    blue_filled.assign(6, 0);
}

void setBlocks(int block_type, Pos pos, int& green_out, int& blue_out, vector<int>& green_removed, vector<int>& blue_removed) {
    int red_row = pos.row, red_col = pos.col;
    int green_stacked, blue_stacked;
    switch(block_type) {
    case 1:
        green_stacked = green_top[red_col];
        blue_stacked = blue_top[red_row];

        green_board[green_stacked][red_col] = block_type;
        green_filled[green_stacked] += 1;
        if(green_filled[green_stacked] == 4) {
            green_removed.push_back(green_stacked);
        }

        blue_board[blue_stacked][red_row] = block_type;
        blue_filled[blue_stacked] += 1;
        if(blue_filled[blue_stacked] == 4) {
            blue_removed.push_back(blue_stacked);
        }

        green_top[red_col] -= 1;
        blue_top[red_row] -= 1;
        break;
    case 2:
        green_stacked = min(green_top[red_col], green_top[red_col+1]);
        blue_stacked = blue_top[red_row];

        green_board[green_stacked][red_col] = 2;
        green_board[green_stacked][red_col+1] = 3;
        blue_board[blue_stacked][red_row] = 4;
        blue_board[blue_stacked-1][red_row] = 5;
        green_top[red_col] = green_stacked - 1;
        green_top[red_col+1] = green_stacked - 1;
        blue_top[red_row] -= 2;

        green_filled[green_stacked] += 2;
        blue_filled[blue_stacked] += 1;
        blue_filled[blue_stacked-1] += 1;
        if(green_filled[green_stacked] == 4) {
            green_removed.push_back(green_stacked);
        }
        if(blue_filled[blue_stacked-1] == 4) {
            blue_removed.push_back(blue_stacked-1);
        }        
        if(blue_filled[blue_stacked] == 4) {
            blue_removed.push_back(blue_stacked);
        }
        break;
    case 3:
        green_stacked = green_top[red_col];
        blue_stacked = min(blue_top[red_row], blue_top[red_row+1]);
        
        green_board[green_stacked][red_col] = 4;
        green_board[green_stacked-1][red_col] = 5;
        blue_board[blue_stacked][red_row] = 2;
        blue_board[blue_stacked][red_row+1] = 3;
        green_top[red_col] -= 2;
        blue_top[red_row] = blue_stacked - 1;
        blue_top[red_row+1] = blue_stacked - 1;

        green_filled[green_stacked] += 1;
        green_filled[green_stacked-1] += 1;
        blue_filled[blue_stacked] += 2;
        if(green_filled[green_stacked-1] == 4) {
            green_removed.push_back(green_stacked-1);
        }  
        if(green_filled[green_stacked] == 4) {
            green_removed.push_back(green_stacked);
        }  
        if(blue_filled[blue_stacked] == 4) {
            blue_removed.push_back(blue_stacked);
        }
        break;
    }

    for(int i=0; i<2; i++) {
        if(green_filled[i] > 0) green_out += 1;
        if(blue_filled[i] > 0) blue_out += 1;
    }
}

void getScoreAndRemoveBlocks(vector<int>& green_removed, vector<int>& blue_removed, int& score) {
    score += (green_removed.size() + blue_removed.size());

    for(int i=0; i<green_removed.size(); i++) {
        int r = green_removed[i];
        green_board[r].assign(4, 0);
    }
    
    for(int j=0; j<blue_removed.size(); j++) {
        int r = blue_removed[j];
        blue_board[r].assign(4, 0);
    }

}

void relocateBlocks(vector<int>& green_removed, vector<int>& blue_removed, int& green_out, int& blue_out) {
    if(green_removed.size() >0) {
        int min_green_removed = green_removed.front();
        int max_green_removed = green_removed.back();
        int removed_cnt = green_removed.size();

        for(int r=max_green_removed; r>=0; r--) {
            if(r>=removed_cnt) {
                green_board[r] = green_board[r-removed_cnt];
            }
            else green_board[r].assign(4, 0);
        }

        for(int c=0; c<4; c++) {
            for(int r=green_top[c]; r<=5; r++) {
                if(green_board[r][c] != 0) {
                    green_top[c] = r-1;
                    break;
                }
                if(r==5) green_top[c] = 5;
            }
        }

        green_removed.clear();
        int top = *min_element(green_top.begin(), green_top.end());
        green_filled.assign(6, 0);
        for(int r=5; r>top; r--) {
            for(int c=0; c<4; c++) {
                if(green_board[r][c]) {
                    green_filled[r] += 1;
                }
            }
            if(green_filled[r] == 4) green_removed.push_back(r);
        }
        sort(green_removed.begin(), green_removed.end());
    }

    if(blue_removed.size() > 0) {
        int min_blue_removed = blue_removed.front();
        int max_blue_removed = blue_removed.back();
        int removed_cnt = blue_removed.size();

        for(int r=max_blue_removed; r>=0; r--) {
            if(r>=removed_cnt) {
                blue_board[r] = blue_board[r-removed_cnt];
            }
            else blue_board[r].assign(4, 0);
        }

        for(int c=0; c<4; c++) {
            for(int r=blue_top[c]; r<=5; r++) {
                if(blue_board[r][c] != 0) {
                    blue_top[c] = r-1;
                    break;
                }
                if(r==5) blue_top[c] = 5;
            }
        }

        blue_removed.clear();
        int top = *min_element(blue_top.begin(), blue_top.end());
        blue_filled.assign(6, 0);
        for(int r=5; r>top; r--) {
            for(int c=0; c<4; c++) {
                if(blue_board[r][c]) {
                    blue_filled[r] += 1;
                }
            }
            if(blue_filled[r] == 4) blue_removed.push_back(r);
        }
        sort(blue_removed.begin(), blue_removed.end());
    }

    green_out = 0, blue_out = 0;
    for(int i=0; i<2; i++) {
        if(green_filled[i] > 0) green_out += 1;
        if(blue_filled[i] > 0) blue_out += 1;
    }

}

void removeBottomGreen(int green_out) {
    for(int i=0; i<green_out; i++) {
        green_board[5-i].assign(4, 0);
    }

    for(int r=5; r>=0; r--) {
        if(r>=green_out) {
            green_board[r] = green_board[r-green_out];
        }
        else green_board[r].assign(4, 0);
    }

    for(int c=0; c<4; c++) {
        green_top[c] += green_out;
        if(green_top[c]>5) green_top[c] = 5;
    }
    for(int r=5; r>=0; r--) {
        if(r>=green_out) {
            green_filled[r] = green_filled[r-green_out];
        }
        else green_filled[r] = 0;
    }
}
void removeBottomBlue(int blue_out) {
    for(int i=0; i<blue_out; i++) {
        blue_board[5-i].assign(4, 0);
    }

    for(int r=5; r>=0; r--) {
        if(r>=blue_out) {
            blue_board[r] = blue_board[r-blue_out];
        }
        else blue_board[r].assign(4, 0);
    }

    for(int c=0; c<4; c++) {
        blue_top[c] += blue_out;
        if(blue_top[c]>5) blue_top[c] = 5;
    }
    for(int r=5; r>=0; r--) {
        if(r>=blue_out) {
            blue_filled[r] = blue_filled[r-blue_out];
        }
        else blue_filled[r] = 0;
    }
}

void solution() {
    int score = 0, remained_blocks = 0;
    for(int i=0; i<N; i++) {
        int block_type = blocks[i].type;
        Pos red_pos = blocks[i].pos;
        vector<int> green_removed, blue_removed;
        int green_out = 0, blue_out = 0;

        setBlocks(block_type, red_pos, green_out, blue_out, green_removed, blue_removed);
        while(green_removed.size() > 0 || blue_removed.size() > 0) {
            getScoreAndRemoveBlocks(green_removed, blue_removed, score);
            relocateBlocks(green_removed, blue_removed, green_out, blue_out);
        }

        if(green_out) {
            removeBottomGreen(green_out);
        }
        if(blue_out) {
            removeBottomBlue(blue_out);
        }

    }

    for(int i=0; i<6; i++) {
        remained_blocks += green_filled[i];
        remained_blocks += blue_filled[i];
    }

    printf("%d\n%d", score, remained_blocks);
}

int main() {
    getInput();
    solution();
}