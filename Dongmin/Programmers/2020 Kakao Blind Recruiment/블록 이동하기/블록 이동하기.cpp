#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
typedef struct Pos {
    int row,col;
} Pos;
typedef struct Robot {
    Pos pos;
    int time;
    bool prevRot;
    bool isHorizontal;
} Robot;
vector<vector<int> > board_cpy;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int twin[2][2] = {{1,0},{0,1}};
bool visited[2][100][100];
int N;

bool isValidPos(const Pos& pos) {
    return pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<N;
}

bool approachGoal(const Robot& r) {
    return (r.isHorizontal && r.pos.row==N-1 && r.pos.col==N-2) || (!r.isHorizontal && r.pos.row==N-2 && r.pos.col==N-1);
}

bool canRotate(const Robot& r, int axis, int lr) {
    Pos checkBlock;
    if(r.isHorizontal && axis && lr) {
        checkBlock = {r.pos.row+1,r.pos.col};
    }
    else if(r.isHorizontal && axis && !lr) {
        checkBlock = {r.pos.row-1,r.pos.col};
    }
    else if(r.isHorizontal && !axis && lr) {
        checkBlock = {r.pos.row+1, r.pos.col+1};
    }
    else if(r.isHorizontal && !axis && !lr) {
        checkBlock = {r.pos.row-1, r.pos.col+1};
    }
    else if(!r.isHorizontal && !axis && lr) {
        checkBlock = {r.pos.row+1, r.pos.col-1};
    }
    else if(!r.isHorizontal && !axis && !lr) {
        checkBlock = {r.pos.row+1, r.pos.col+1};
    }
    else if(!r.isHorizontal && axis && lr){
        checkBlock = {r.pos.row, r.pos.col+1};
    }
    else {
        checkBlock = {r.pos.row, r.pos.col-1};
    }
    return isValidPos(checkBlock) && !board_cpy[checkBlock.row][checkBlock.col];
}

Pos getNewPos(const Robot& r, int axis, int lr) {
    Pos newBlock;
    if(r.isHorizontal && axis && lr) {
        newBlock = {r.pos.row, r.pos.col+1};
    }
    else if(r.isHorizontal && axis && !lr) {
        newBlock = {r.pos.row-1,r.pos.col+1};
    }
    else if(r.isHorizontal && !axis && lr) {
        newBlock = {r.pos.row, r.pos.col};
    }
    else if(r.isHorizontal && !axis && !lr) {
        newBlock = {r.pos.row-1, r.pos.col};
    }
    else if(!r.isHorizontal && !axis && lr) {
        newBlock = {r.pos.row, r.pos.col-1};
    }
    else if(!r.isHorizontal && !axis && !lr) {
        newBlock = {r.pos.row, r.pos.col};
    }
    else if(!r.isHorizontal && axis && lr){
        newBlock = {r.pos.row+1, r.pos.col};
    }
    else {
        newBlock = {r.pos.row+1, r.pos.col-1};
    }
    return newBlock;
}

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    N = board.size();
    board_cpy = board;
    queue<Robot> q;
    memset(visited, 0, sizeof(visited));

    q.push(Robot{Pos{0,0}, 0, 0, 1});
    visited[1][0][0] = 1;
    while(!q.empty()) {
        Robot r = q.front();
        //cout << "time:" << r.time << ", pos=(" << r.pos.row <<", " << r.pos.col <<"), isHorizontal=" << r.isHorizontal <<
        //", prevRot=" << r.prevRot << "\n"; 
        q.pop();

        if(approachGoal(r)) {
            if(answer > r.time) {
                answer = r.time;
                break;
            }
        }

        for(int i=0; i<4; i++) {
            Pos there = Pos{r.pos.row + dir[i][0], r.pos.col + dir[i][1]};
            Pos twinPos = Pos{there.row + twin[r.isHorizontal][0], there.col + twin[r.isHorizontal][1]};
            if(isValidPos(there) && isValidPos(twinPos) && !visited[r.isHorizontal][there.row][there.col] 
                && !board[there.row][there.col] && !board[twinPos.row][twinPos.col]) {
                visited[r.isHorizontal][there.row][there.col] = 1;
                q.push(Robot{there, r.time+1, 0, r.isHorizontal});
            }
        }

        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                Pos newPos = getNewPos(r,i,j);
                Pos twinPos = Pos{newPos.row + twin[!r.isHorizontal][0], newPos.col + twin[!r.isHorizontal][1]};
                if(!r.prevRot && canRotate(r,i,j) && !visited[!r.isHorizontal][newPos.row][newPos.col]
                    && isValidPos(newPos) && isValidPos(twinPos) && !board[newPos.row][newPos.col] && !board[twinPos.row][twinPos.col]) {                    
                    q.push(Robot{newPos, r.time+1, 1, !r.isHorizontal});
                    visited[!r.isHorizontal][newPos.row][newPos.col] = 1;
                }
            }
        }
    }

    return answer;
}