#include <string>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
typedef struct Pos {
    int row,col;
} Pos;

typedef struct Path {
    Pos pos;
    int cost;
    int dir;
} Path;

int N;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<vector<int> > vc;
bool isValidPos(const Pos& pos) {
    return pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<N;
}

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    N = board.size();
    vc.assign(N, vector<int>(N, 987654321));

    queue<Path> q;

    Path a;
    vc[0][0]= 0;
    if(!board[0][1]) {
        vc[0][1] = 100;
        q.push(Path{{0,1}, 100, 1});
    }
    if(!board[1][0]) {
        vc[1][0] = 100;
        q.push(Path{{1,0}, 100, 2});
    }

    while(!q.empty()) {
        Path p = q.front();
        q.pop();
        if(p.cost > answer) {
            continue;
        }

        if(p.pos.row == N-1 && p.pos.col == N-1) {
            if(answer > p.cost) {
                answer = p.cost;
            }
        }
        else {
            for(int i=0; i<4; i++) {
                Pos there = Pos{p.pos.row + dir[i][0], p.pos.col + dir[i][1]};
                if(isValidPos(there) && !board[there.row][there.col]) {
                    if(p.dir == i) {
                        if(vc[there.row][there.col] >= p.cost+100) {
                            vc[there.row][there.col] = p.cost+100;
                            q.push(Path{there, p.cost+100, i});
                        }
                    }
                    else {
                        if(vc[there.row][there.col] >= p.cost+600) {
                            vc[there.row][there.col] = p.cost+600;
                            q.push(Path{there, p.cost+600, i});
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}
