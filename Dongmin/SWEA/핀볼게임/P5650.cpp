#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct Pos{
    int row;
    int col;
}Pos;
typedef struct Ball{
    Pos pos;
    int dir;
} Ball;
bool operator==(const Pos& a, const Pos& b) {
    return a.row==b.row && a.col==b.col;
}
Pos operator+(const Pos& a, const Pos& b) {
    return Pos{a.row+b.row,a.col+b.col};
}
bool operator<(const Pos& a, const Pos& b) {
    if(a.row<b.row) {
        return true;
    } else if(a.row==b.row){
        return a.col<b.col;
    }
    return false;
}

int N;
vector<vector<int> > board;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
vector<int> blocks[6];
vector<Pos> holes[5];
map<Pos, Pos> wormhole;

Ball ball;

void getInput() {
    cin>>N;
    board.assign(N,vector<int>(N,0));
    wormhole.clear();
    for(int i=0;i<5;i++){
        holes[i].clear();
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
            if(board[i][j]==6){
                holes[0].push_back(Pos{i,j});
            } else if(board[i][j]==7){
                holes[1].push_back(Pos{i,j});
            } else if(board[i][j]==8){
                holes[2].push_back(Pos{i,j});
            } else if(board[i][j]==9){
                holes[3].push_back(Pos{i,j});
            } else if(board[i][j]==10){
                holes[4].push_back(Pos{i,j});
            }
        }
    }

    for(int i=0; i<5; i++){
        if(holes[i].size()>0){
            wormhole.insert(make_pair(holes[i][0],holes[i][1]));
            wormhole.insert(make_pair(holes[i][1],holes[i][0]));
        }
    }
    blocks[1]={2,3,1,0};
    blocks[2]={1,3,0,2};
    blocks[3]={3,2,0,1};
    blocks[4]={2,0,3,1};
    blocks[5]={2,3,0,1};
}
bool isWall(Pos pos){
    return !(pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<N);
}

void pinBall(Pos init, int& max) {
    int score = 0;
    bool hitWall=false;
    do {
        Pos newpos=hitWall?ball.pos:ball.pos + Pos{dr[ball.dir],dc[ball.dir]};

        if(isWall(newpos)) {
            ball.dir=blocks[5][ball.dir];
            score += 1;
            hitWall=true;
        }
        else if(board[newpos.row][newpos.col] > 0) {
            if(board[newpos.row][newpos.col] < 6) {
                int blocknum = board[newpos.row][newpos.col];
                ball.pos=newpos;
                ball.dir=blocks[blocknum][ball.dir];
                score += 1;
                hitWall=false;
            }
            else {
                ball.pos=wormhole.find(newpos)->second;
                hitWall=false;
            }
        }
        else{
            ball.pos=newpos;
            hitWall=false;
        }

        //printf("ball pos = (%d,%d) dir=%d, init = (%d,%d)\n", ball.pos.row, ball.pos.col, ball.dir,init.row,init.col);
    }while(!(ball.pos==init) && board[ball.pos.row][ball.pos.col]!=-1);

    if(score>max){
        max=score;
    }
}

void solution(int testnum) {
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<4; k++){
                if(board[i][j]==0) {
                    ball.pos = {i,j};
                    ball.dir = k;
                    //printf("start ball.pos=(%d,%d), dir=%d\n", ball.pos.row,ball.pos.col,ball.dir);
                    pinBall(Pos{i,j}, ans);
                }
            }
        }
    }

    printf("#%d %d\n", testnum, ans);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution(test_case);
	}
	return 0;
}