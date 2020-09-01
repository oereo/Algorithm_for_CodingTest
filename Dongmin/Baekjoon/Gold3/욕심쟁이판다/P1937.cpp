#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row;
    int col;
}Pos;
typedef struct Bamboo {
    int size;
    Pos pos;
} Bamboo;
struct compare {
    bool operator()(const Bamboo& a, const Bamboo& b) {
        if(a.size != b.size)
            return a.size<b.size;
        else if(a.pos.row != b.pos.row)
            return a.pos.row>b.pos.row;
        else
            return a.pos.col>b.pos.col;
    }
};

int N,ans=0;
vector<vector<int> > map;
vector<vector<int> > dp;
priority_queue<Bamboo,vector<Bamboo>,compare> pq;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void getInput() {
    cin >> N;
    map.assign(N, vector<int>(N, -1));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            pq.push({map[i][j],{i,j}});
        }
    }
    dp.assign(N, vector<int>(N, -1));
}
bool isValidPos(Pos pos){ 
    return pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<N;
}

void dfs(Pos pos, int depth) {
    if(depth>dp[pos.row][pos.col]){
        dp[pos.row][pos.col] = depth;
        if(depth>ans) ans=depth;
    }

    for(int i=0; i<4; i++) {
        Pos newpos = Pos{pos.row+dr[i], pos.col+dc[i]};
        if(isValidPos(newpos) && map[pos.row][pos.col]<map[newpos.row][newpos.col])
        {
            if(dp[newpos.row][newpos.col]==-1)
            {
                dfs(newpos, depth+1);
            }
            else 
            {
                if(dp[newpos.row][newpos.col]+1>dp[pos.row][pos.col])
                {
                    dp[pos.row][pos.col] = dp[newpos.row][newpos.col]+1;
                    if(dp[pos.row][pos.col]>ans) ans=dp[pos.row][pos.col];
                }
            }
        }
    }
}
void solution() {
    while(!pq.empty())
    {
        Bamboo bam=pq.top();
        pq.pop();
        dfs(bam.pos, 1);
    }
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}