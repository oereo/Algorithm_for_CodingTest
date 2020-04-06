// DFS 실패 : visit 벡터를 m*n*2 크기로 설정하여 방향에 따라 저장해야 함

#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;
int M, N, answer;
int dirs[2][2] = {{0,1}, {1,0}};
vector<vector<int>> map;

void DFS(int x, int y, int dir, vector<vector<int>> visit){
    if(x == M - 1 && y == N - 1){
        answer++;
        answer = answer % MOD;
        return;
    }
    if(map[x][y] == 0){
        for(int i = 0; i < 2; i++){
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= M || ny >= N) continue;
            if(map[nx][ny] != 1){
                visit[nx][ny] = 1;
                DFS(nx, ny, i+1, visit);
                visit[nx][ny] = 0;
            }
        }
    }
    if(map[x][y] == 2){
        if(dir == 1)
            y++;
        else
            x++;
        if(x >= M || y >= N) return;
        if(map[x][y] != 1){
            visit[x][y] = 1;
            DFS(x, y, dir, visit);
            visit[x][y] = 0;
        }
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {
    map = city_map, M = m, N = n;
    vector<vector<int>> visit(M, vector<int>(N));
    visit[0][0] = 1;
    DFS(0,0,0,visit);
    return answer;
}