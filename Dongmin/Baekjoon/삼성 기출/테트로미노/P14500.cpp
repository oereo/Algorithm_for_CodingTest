#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row, col;
} Pos;
typedef struct Polyomino {
    vector<Pos> positions; 
} Polyomino;

int N, M;
vector<vector<int> > board;
vector<vector<Polyomino> > polyominos;
int poly_case[5] = {2, 1, 8, 4, 4};

void getInput() {
    cin >> N >> M;
    board.assign(N, vector<int>(M,0));
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++) {
            cin >> board[r][c];
        }
    }

    polyominos.assign(5, vector<Polyomino>(8, Polyomino{vector<Pos>()}));
    for(int i=0; i<4; i++) polyominos[0][0].positions.push_back({-i,0});
    for(int i=0; i<4; i++) polyominos[0][1].positions.push_back({0,i});

    polyominos[1][0].positions.push_back({0,0});
    polyominos[1][0].positions.push_back({-1,0});
    polyominos[1][0].positions.push_back({0,1});
    polyominos[1][0].positions.push_back({-1,1});
    
    polyominos[2][0].positions.push_back({0,0});
    polyominos[2][0].positions.push_back({-1,0});
    polyominos[2][0].positions.push_back({0,1});
    polyominos[2][0].positions.push_back({-2,0});

    polyominos[2][1].positions.push_back({0,0});
    polyominos[2][1].positions.push_back({-1,0});
    polyominos[2][1].positions.push_back({-1,1});
    polyominos[2][1].positions.push_back({-1,2});

    polyominos[2][2].positions.push_back({0,1});
    polyominos[2][2].positions.push_back({-1,1});
    polyominos[2][2].positions.push_back({-2,1});
    polyominos[2][2].positions.push_back({-2,0});
    
    polyominos[2][3].positions.push_back({0,0});
    polyominos[2][3].positions.push_back({0,1});
    polyominos[2][3].positions.push_back({0,2});
    polyominos[2][3].positions.push_back({-1,2});

    polyominos[2][4].positions.push_back({-1,0});
    polyominos[2][4].positions.push_back({-1,1});
    polyominos[2][4].positions.push_back({-1,2});
    polyominos[2][4].positions.push_back({0,2});

    polyominos[2][5].positions.push_back({0,0});
    polyominos[2][5].positions.push_back({0,1});
    polyominos[2][5].positions.push_back({0,2});
    polyominos[2][5].positions.push_back({-1,0});

    polyominos[2][6].positions.push_back({0,0});
    polyominos[2][6].positions.push_back({0,1});
    polyominos[2][6].positions.push_back({-1,1});
    polyominos[2][6].positions.push_back({-2,1});

    polyominos[2][7].positions.push_back({0,0});
    polyominos[2][7].positions.push_back({-1,0});
    polyominos[2][7].positions.push_back({-2,0});
    polyominos[2][7].positions.push_back({-2,1});

    polyominos[3][0].positions.push_back({-1,0});
    polyominos[3][0].positions.push_back({-2,0});
    polyominos[3][0].positions.push_back({0,1});
    polyominos[3][0].positions.push_back({-1,1});

    polyominos[3][1].positions.push_back({0,0});
    polyominos[3][1].positions.push_back({0,1});
    polyominos[3][1].positions.push_back({-1,1});
    polyominos[3][1].positions.push_back({-1,2});

    polyominos[3][2].positions.push_back({0,0});
    polyominos[3][2].positions.push_back({-1,0});
    polyominos[3][2].positions.push_back({-1,1});
    polyominos[3][2].positions.push_back({-2,1});

    polyominos[3][3].positions.push_back({-1,0});
    polyominos[3][3].positions.push_back({-1,1});
    polyominos[3][3].positions.push_back({0,1});
    polyominos[3][3].positions.push_back({0,2});

    polyominos[4][0].positions.push_back({-1,0});
    polyominos[4][0].positions.push_back({0,1});
    polyominos[4][0].positions.push_back({-1,1});
    polyominos[4][0].positions.push_back({-1,2});

    polyominos[4][1].positions.push_back({0,0});
    polyominos[4][1].positions.push_back({-1,0});
    polyominos[4][1].positions.push_back({-2,0});
    polyominos[4][1].positions.push_back({-1,1});

    polyominos[4][2].positions.push_back({-1,0});
    polyominos[4][2].positions.push_back({0,1});
    polyominos[4][2].positions.push_back({-1,1});
    polyominos[4][2].positions.push_back({-2,1});

    polyominos[4][3].positions.push_back({0,0});
    polyominos[4][3].positions.push_back({0,1});
    polyominos[4][3].positions.push_back({0,2});
    polyominos[4][3].positions.push_back({-1,1});
}
bool isValidPos(Pos& pos) {
    return pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M;
}

void getMaxPolyominoPosition(Pos pos, Polyomino polyomino, int& max) {
    int sum = 0;
    for(int p=0; p<4; p++) {
        Pos laid_pos = {pos.row + polyomino.positions[p].row, pos.col + polyomino.positions[p].col};
        if(isValidPos(laid_pos)) {
            sum += board[laid_pos.row][laid_pos.col];
        }
        else return;
    }

    if(sum > max) {
        max = sum;
    }
}

void solution() {
    int ans = 0;
    for(int poly = 0; poly < 5; poly++) {
        for(int pc = 0; pc < poly_case[poly]; pc++) {
            Polyomino selected = polyominos[poly][pc];
            for(int r=0; r<N; r++) {
                for(int c=0; c<M; c++) {
                    getMaxPolyominoPosition(Pos{r,c}, selected, ans);
                }
            }
        }
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}