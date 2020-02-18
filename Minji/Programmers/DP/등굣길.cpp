#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int BFS(int n, int m){
    queue<int> q;
    q.push(0);
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        if(x == n-1 && y == m-1)
            return map[x][y];
        for(int i = 0; i < 4; i++){
            if(x + dir[i][0] < 0 || x + dir[i][0] >= n || y + dir[i][1] < 0 || y + dir[i][1] >= m)
                continue;
            if(map[x + dir[i][0]][y + dir[i][1]] != -1){
                if(visited[x + dir[i][0]][y + dir[i][1]] == 0){
                    visited[x + dir[i][0]][y + dir[i][1]] = 1;
                    q.push(x + dir[i][0]);
                    q.push(y + dir[i][1]);
                }
                map[x + dir[i][0]][y + dir[i][1]] += map[x][y];
                map[x + dir[i][0]][y + dir[i][1]] %= 1000000007;
            }
        }
    }
    return 0;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    map.assign(n, vector<int>(m,0));
    visited.assign(n, vector<int>(m,0));
    int len = puddles.size();
    map[0][0] = 1;
    visited[0][0] = 1;
    for(int i = 0; i < len; i++)
        map[puddles[i][1]-1][puddles[i][0]-1] = -1;
    int answer = BFS(n,m);
    return answer;
}
