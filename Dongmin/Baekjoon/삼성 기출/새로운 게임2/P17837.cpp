#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct Slot {
    int type;
    vector<int> player; 
} Slot;
typedef struct Player {
    int r,c;
    int d;
} Player;
int N, K;

const int WHITE = 0, RED = 1, BLUE = 2;

vector<vector<Slot> > board;
Player players[11];
int dir[5][2] = { {-1,-1}, {0,1}, {0,-1}, {-1,0}, {1,0} };

void printAllState(int turn) {
    printf("=== turn %d ===\n",turn);
    printf("players: \n");
    for(int i=1; i<=K; i++) {
        printf("player#%d = { r=%d, c=%d ,d=%d }\n", i, players[i].r, players[i].c, players[i].d);
    }
    printf("\nboard: \n");
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            printf("( type = %d, ", board[i][j].type);
            printf(" {");
            for(int k=0; k<board[i][j].player.size(); k++) {
                printf(" %d", board[i][j].player[k]);
            }
            printf("} ) ");
        }
        printf("\n");
    }
}

void getInput() {
    cin >> N >> K;
    Slot slot = Slot{0, vector<int>()};
    board.assign(N+1, vector<Slot>(N+1, slot));

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> board[i][j].type;
        }
    }  

    for(int i=1; i<=K; i++) {
        cin >> players[i].r >> players[i].c >> players[i].d;
        board[players[i].r][players[i].c].player.push_back(i);
    }
}

bool isValidPos(int r, int c) {
    return r>=1 && r<=N && c>=1 && c<=N;
}

void doWhiteMove(int pnum, int nr, int nc) {
    int now_row = players[pnum].r, now_col = players[pnum].c;

    // 얘 위에 다른 말이 있는가
    vector<int>& now_que = board[now_row][now_col].player;
    vector<int>& next_que = board[nr][nc].player;
    bool is_top = (now_que.back() == pnum);
    if(is_top) 
    {
        now_que.pop_back();
        next_que.push_back(pnum);
    }
    else
    {
        int player_pos;
        for(int i=0; i<now_que.size(); i++)
        {
            if(now_que[i] == pnum) player_pos = i;
        }

        vector<int> cpy_player;
        cpy_player.assign(now_que.begin() + player_pos, now_que.end());
        now_que.erase(now_que.begin() + player_pos, now_que.end());

        next_que.insert(next_que.end(), cpy_player.begin(), cpy_player.end());
        for(int i=1; i<cpy_player.size(); i++)
        {
            players[cpy_player[i]].r = nr;
            players[cpy_player[i]].c = nc;
        }
    }

    players[pnum].r = nr; players[pnum].c = nc;
}

void doRedMove(int pnum, int nr, int nc) {
    int now_row = players[pnum].r, now_col = players[pnum].c;

    // 얘 위에 다른 말이 있는가
    vector<int>& now_que = board[now_row][now_col].player;
    vector<int>& next_que = board[nr][nc].player;
    bool is_top = (now_que.back() == pnum);
    if(is_top) 
    {
        now_que.pop_back();
        next_que.push_back(pnum);
        players[pnum].r = nr; players[pnum].c = nc;
    }
    else
    {
        vector<int> cpy_player; int p;
        do {
            p = now_que.back();
            now_que.pop_back();
            players[p].r = nr;
            players[p].c = nc;
            cpy_player.push_back(p);
        } while(p != pnum);

        next_que.insert(next_que.end(), cpy_player.begin(), cpy_player.end());
    }
}

void doBlueMove(int pnum, int r, int c) {
    int& d = players[pnum].d;

    if(d == 1 || d == 3) d += 1;
    else if(d == 2 || d == 4) d -= 1;

    int nr = r + dir[d][0], nc = c + dir[d][1];
    if(isValidPos(nr,nc)) 
    {
        int slot_type = board[nr][nc].type;
        if(slot_type != BLUE)
        {
            if(slot_type == RED) {
                doRedMove(pnum, nr, nc);
            }
            else if(slot_type == WHITE) {
                doWhiteMove(pnum, nr, nc);
            }
        } 
    }
}

void solution() {
    int ans = -1;
    //printAllState(0);
    bool isUpFour = false;
    for(int turn = 1; !isUpFour && turn <= 1000; turn++)
    {
        for(int k = 1; k <= K; k++)
        {
            int d = players[k].d;
            int r = players[k].r, c = players[k].c;
            int nr = r + dir[d][0], nc = c + dir[d][1];

            if(isValidPos(nr, nc))
            {
                switch(board[nr][nc].type)
                {
                    case WHITE:
                        doWhiteMove(k, nr, nc);
                        break;
                    case RED:
                        doRedMove(k, nr, nc);
                        break;
                    case BLUE:
                        doBlueMove(k, r, c);
                        break;
                }
            }
            else 
            {
                doBlueMove(k, r, c);
            }

            if(board[players[k].r][players[k].c].player.size() >= 4)
            {
                ans = turn;
                isUpFour = true;
                break;
            }
        }

    }
    
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}