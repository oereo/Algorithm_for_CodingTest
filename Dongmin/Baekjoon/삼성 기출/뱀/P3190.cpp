#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct TimeDir {
    int time;
    char isLeft;
} TimeDir;
typedef struct Pos {
    int row, col;
} Pos;

vector<vector<int> > board;
vector<TimeDir> time_dirs;
int N, K, L;
int move_unit[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

void getInput() {
    cin >> N >> K;
    board.assign(N+1, vector<int>(N+1, 0));
    for(int i=0; i<K; i++) {
        int r,c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    cin >> L;
    board[1][1] = 2;
    for(int i=0; i<L; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        if(dir == 'D') {
            time_dirs.push_back({time, 0});
        }
        else {
            time_dirs.push_back({time, 1});
        }
    }
}

bool isValidPos(Pos& pos) {
    return pos.row >=1 && pos.row<=N && pos.col >= 1 && pos.col <= N;
}
bool isApplePos(Pos& pos) {
    return board[pos.row][pos.col] == 1;
}
bool isCrashed(Pos& pos) {
    return board[pos.row][pos.col] == 2;
}
void printBoard() {
    for(int r=1; r<=N; r++) {
        for(int c=1; c<=N; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}
void solution() {
    int ans = 0;
    int snake_direction = 0;
    Pos head_position = {1,1};
    queue<Pos> snake_trace;
    snake_trace.push({1,1});

    for(int time = 1, idx = 0; ; time++) {
        int rotate_time, is_rotate_left;
        if(idx < L) {
            rotate_time = time_dirs[idx].time;
            is_rotate_left = time_dirs[idx].isLeft;
        }

        Pos next_pos = { head_position.row + move_unit[snake_direction][0], head_position.col + move_unit[snake_direction][1]};
        if(!isValidPos(next_pos) || isCrashed(next_pos)) {
            ans = time;
            break;
        }
        else if(isApplePos(next_pos)) {
            board[next_pos.row][next_pos.col] = 2;
            snake_trace.push(next_pos);
        }
        else {
            Pos tail_position = snake_trace.front();
            snake_trace.pop();
            board[tail_position.row][tail_position.col] = 0;
            board[next_pos.row][next_pos.col] = 2;
            snake_trace.push(next_pos);
        }

        head_position = next_pos;
        if(idx < L) {
            if(time == rotate_time) {
                snake_direction = is_rotate_left ? snake_direction + 1 : snake_direction - 1;
                if(snake_direction < 0) snake_direction += 4;
                else if(snake_direction >= 4) snake_direction -= 4;
                idx++;
            }
        }
    }

    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}