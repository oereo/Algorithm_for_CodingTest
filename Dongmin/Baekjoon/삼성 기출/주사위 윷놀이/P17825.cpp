#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int RED=0, BLUE=1;
typedef struct Player {
    bool isArrived;
    int pos;
    int state;
} Player;
typedef struct Slot {
    bool isOccupied;
    int score;
    int next;
    int blueNext;
} Slot;

Player players[4];
vector<Slot> board;
int moves[10];

void getInput() {
    board = {
        {1,0,1,-1}, {0,2,2,-1}, {0,4,3,-1}, {0,6,4,-1}, {0,8,5,-1}, {0,10,6,20},
        {0,12,7,-1}, {0,14,8,-1}, {0,16,9,-1}, {0,18,10,-1}, {0,20,11,23},
        {0,22,12,-1}, {0,24,13,-1}, {0,26,14,-1}, {0,28,15,-1}, {0,30,16,25},
        {0,32,17,-1}, {0,34,18,-1}, {0,36,19,-1}, {0,38,31,-1},
        {0,13,21,-1}, {0,16,22,-1}, {0,19,28,-1}, {0,22,24,-1}, {0,24,28,-1},
        {0,28,26,-1}, {0,27,27,-1}, {0,26,28,-1}, {0,25,29,-1}, {0,30,30,-1},
        {0,35,31,-1}, {0,40,32,-1}, {0,0,-1,-1}
    };
    memset(players, 0, sizeof(players));

    for(int i=0; i<10; i++) {
        cin >> moves[i];
    }
}

void dfs(int turn, int player, int sum, int &max) {
    if(turn == 10) {
        if(sum > max) max = sum;
        return;
    }
    else {
        int start = players[player].pos;
        int orgState = players[player].state;

        for(int i=0; i<moves[turn]; i++) {
            int now = players[player].pos;
            players[player].pos = players[player].state == BLUE ? board[now].blueNext : board[now].next;
            players[player].state = RED;

            if(players[player].pos == 32) {
                players[player].isArrived = 1;
                break;
            }
        }

        if(!players[player].isArrived) {
            if(board[players[player].pos].isOccupied) {
                players[player].pos = start;
                players[player].state = orgState;
                return;
            }

            if(board[players[player].pos].blueNext != -1) {
                players[player].state = BLUE;
            }

            board[start].isOccupied = 0;
            board[players[player].pos].isOccupied = 1;
        }
        else {
            board[start].isOccupied = 0;
        }

        for(int p=0; p<4; p++) {
            if(!players[p].isArrived) {
                dfs(turn+1, p, sum+board[players[player].pos].score, max);
            }
        }

        // 되돌리기
        board[players[player].pos].isOccupied = 0;
        board[start].isOccupied = 1;
        players[player].isArrived = 0;
        players[player].state = orgState;
        players[player].pos = start;
    }
}

void solution() {
    int ans = 0;
    dfs(0,0,0,ans);
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
    return 0;
}