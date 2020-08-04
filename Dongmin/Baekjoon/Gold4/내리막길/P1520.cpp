// TODO 다시 생각하기
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int M,N,ans=0;
vector<vector<int> > map;
vector<vector<int> > dp;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void getInput() {
    cin >> M >> N;
    map.assign(M+2, vector<int>(N+2, -1));
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }
    dp.assign(M+2, vector<int>(N+2, 0));
}

void dfs(int r, int c){
    if(r==M && c==N) {
        dp[r][c] = 1;
    } else if(!dp[r][c]) {
        for(int i=0; i<4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(map[r][c]>0 && map[r][c]>map[nr][nc]) {
                dfs(nr,nc);
                if (dp[r][c] < 0 && dp[nr][nc]>0) dp[r][c] = 0;
				if (dp[nr][nc] > 0) dp[r][c] += dp[nr][nc];
				else if (!dp[r][c]) dp[r][c] = -1;
            }
        }
    }
}

void solution() {
    dfs(1,1);
    ans = dp[1][1]<0?0:dp[1][1];
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}