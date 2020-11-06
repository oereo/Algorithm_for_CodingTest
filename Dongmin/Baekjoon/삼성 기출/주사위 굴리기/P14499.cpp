#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row,col;
} Pos;

Pos dice_pos;
int N,M,K;
vector<vector<int> > map;
vector<int> commands;
int move_unit[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int dice[6] = {0, 0, 0, 0, 0 ,0};
int side_index[6] = {0, 1, 3, 4, 5, 2};

void getInput() {
    cin >> N >> M >> dice_pos.row >> dice_pos.col >> K;
    map.assign(N, vector<int>(M, 0));
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++) {
            cin >> map[r][c];
        }
    }

    commands.assign(K, 0);
    for(int i=0; i<K; i++) {
        int dir;
        cin >> dir;
        commands[i] = dir-1;
    }
}

bool isValidsPos(Pos& pos) {
    return pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<M;
}
void changeSideIndex(int direction) {
    int new_side_index[6] = {0, 0, 0, 0, 0, 0};
    
    enum DIRECTION { RIGHT, LEFT, UP, DOWN };
    switch(direction) {
    case DIRECTION::RIGHT:
        new_side_index[0] = side_index[4];
        new_side_index[1] = side_index[1];
        new_side_index[2] = side_index[2];
        new_side_index[3] = side_index[0];
        new_side_index[4] = side_index[5];
        new_side_index[5] = side_index[3];
        break;
    case DIRECTION::LEFT:
        new_side_index[0] = side_index[3];
        new_side_index[1] = side_index[1];
        new_side_index[2] = side_index[2];
        new_side_index[3] = side_index[5];
        new_side_index[4] = side_index[0];
        new_side_index[5] = side_index[4];
        break;
    case DIRECTION::UP:
        new_side_index[0] = side_index[2];
        new_side_index[1] = side_index[0];
        new_side_index[2] = side_index[5];
        new_side_index[3] = side_index[3];
        new_side_index[4] = side_index[4];
        new_side_index[5] = side_index[1];
        break;
    case DIRECTION::DOWN:
        new_side_index[0] = side_index[1];
        new_side_index[1] = side_index[5];
        new_side_index[2] = side_index[0];
        new_side_index[3] = side_index[3];
        new_side_index[4] = side_index[4];
        new_side_index[5] = side_index[2];
        break;
    }

    memcpy(side_index, new_side_index, sizeof(side_index));
}

void solution() {
    for(int idx = 0; idx < K; idx++) {
        int direction = commands[idx];
        Pos new_pos = { dice_pos.row + move_unit[direction][0], dice_pos.col + move_unit[direction][1] };

        if(isValidsPos(new_pos)) {
            changeSideIndex(direction);
            if(map[new_pos.row][new_pos.col] != 0) {
                dice[side_index[0]] = map[new_pos.row][new_pos.col];
                map[new_pos.row][new_pos.col] = 0;
            }
            else {
                map[new_pos.row][new_pos.col] = dice[side_index[0]];
            }

            dice_pos = new_pos;
            cout << dice[side_index[5]] << endl;
        }
    }
}

int main() {
    getInput();
    solution();
}