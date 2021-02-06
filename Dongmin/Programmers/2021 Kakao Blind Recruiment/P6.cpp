#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Pos {
    int r,c;
};
struct CountPos {
    int count;
    Pos pos;
};

ostream& operator<<(ostream& os, Pos& p) {
    os << "(" << p.r << ", " << p.c << ")";
    return os;
}
bool operator==(Pos& a, Pos& b) {
    return a.r==b.r && a.c==b.c;
}

map<int, vector<Pos> > card_pos;
int dir[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};

bool isValidPos(int r, int c) {
    return r>=0&&r<4 && c>=0&&c<4;
}

Pos getControlPos(vector<vector<int> >& board, int d, Pos current) {
    
    int cr = current.r + dir[d][0];
    int cc = current.c + dir[d][1];
    
    while (isValidPos(cr,cc) && !board[cr][cc]) {
        cr += dir[d][0];
        cc += dir[d][1];
    }
    
    if (!isValidPos(cr,cc)) {
        return Pos{cr-dir[d][0], cc-dir[d][1]};
    }
    return Pos{cr,cc};
}

int getMinimumByBFS(vector<vector<int> >& board, Pos start, Pos dest) {
    
    int min_cnt = 0;
    queue<CountPos> qu;
    qu.push(CountPos{0, start});

    while (!qu.empty()) {
        CountPos cp = qu.front();
        qu.pop();
        if (cp.pos == dest) {
            min_cnt = cp.count;
            board[dest.r][dest.c] = 0;
            break;
        }
        
        for (int d=0; d<4; d++) {
            int new_r = cp.pos.r + dir[d][0];
            int new_c = cp.pos.c + dir[d][1];
            if (!isValidPos(new_r, new_c)) continue;
            qu.push({cp.count+1, Pos{new_r, new_c}});
        }
            
        for (int cd=0; cd<4; cd++) {
            Pos new_pos = getControlPos(board, cd, cp.pos);
            if (new_pos == cp.pos) continue;
            qu.push({cp.count+1, new_pos});
        }
    }
    
    return min_cnt;
}

void dfs(vector<vector<int> > board, vector<int> sequence, int move_cnt,
        int seq_idx, int card_idx, Pos start, int& minimum) {
    if (move_cnt > minimum) return;    
    
    if (seq_idx == sequence.size()) {
        
        if (minimum > move_cnt) {
            minimum = move_cnt;
            return;
        }
    }
    else {
        
        // bfs
        int card_num = sequence[seq_idx];
        Pos first_dest = card_pos[card_num][card_idx];
        Pos second_dest = card_pos[card_num][(card_idx==0)?1:0];
        
        int min_cnt = 0;
        
        // 첫번째 목표까지 최소 카운 계산
        min_cnt += getMinimumByBFS(board, start, first_dest);
        // 두번째 목표까지 최소 카운트 계산
        min_cnt += getMinimumByBFS(board, first_dest, second_dest);
        
        dfs(board, sequence, move_cnt+min_cnt, seq_idx+1, 0, second_dest, minimum);
        dfs(board, sequence, move_cnt+min_cnt, seq_idx+1, 1, second_dest, minimum);
    }
}

int getMinimumMoveCount(vector<vector<int> > board, vector<int> sequence, int r, int c) {
    
    Pos start_pos = {r, c};
    int card_num = sequence.size();
    
    int first_card_case = 9876; 
    dfs(board, sequence, 0, 0, 0, start_pos, first_card_case);
    int second_card_case = 9876; 
    dfs(board, sequence, 0, 0, 1, start_pos, second_card_case);
    
    return min(first_card_case, second_card_case);
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
   
    // 무슨 카드가 있는가 체크한다.
    // 카드의 위치도 체크한다.
    bool check[7] = {0,};
    vector<int> cards;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int num = board[i][j];
            if (num && !check[num]) {
                card_pos[num] = vector<Pos>();
                check[num] = 1;
                cards.push_back(num);
            }
            
            if (num) card_pos[num].push_back(Pos{i,j});
        }
    }
    
    sort(cards.begin(), cards.end());
    vector<vector<int> > seq_combs;
    // 제거할 카드의 순서 조합을 구한다.
    do {
        vector<int> seq;
        
        seq.assign(cards.begin(), cards.end());
        seq_combs.push_back(seq);
    } while(next_permutation(cards.begin(), cards.end()));
    
    // 제거할 카드 개수의 x2 만큼의 엔터키 입력이 필수
    // 최소를 결정하는 것은 이동 횟수 -> 이동 횟수만 따지고 마지막에 더한다.
    
    int min_cnt = 1000;
    for (int i=0; i<seq_combs.size(); i++) {
        
        vector<int> sequence = seq_combs[i];
        int move_cnt = getMinimumMoveCount(board, sequence, r, c);
        if (min_cnt > move_cnt) {
            min_cnt = move_cnt;
        }
    }
    
    answer = min_cnt + cards.size()*2;
    return answer;
}