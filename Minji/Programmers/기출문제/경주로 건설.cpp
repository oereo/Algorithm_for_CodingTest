#include <vector>
#include <queue>

using namespace std;

struct Node{
    int x;
    int y;
    int d;
    int s;
    int c;
};

struct cmp{
    bool operator()(Node a, Node b) {
        return (a.s + a.c * 5) > (b.s + b.c * 5);
    }
};

int solution(vector<vector<int>> board) {
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int len = board.size();
    int result[25][25][4];    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++){
            for(int k = 0; k < 4; k++) {                
                result[i][j][k] = 987654321;
            }
        }
    }    
    for(int i = 0; i < 4; i++) {                
        result[0][0][i] = 0;
    }
    
    priority_queue<Node, vector<Node>, cmp> q;
    if(board[0][1] == 0){
        q.push({0,1,0,1,0});
        result[0][1][0] = 100;
    }
    if(board[1][0] == 0) {
        q.push({1,0,1,1,0});
        result[1][0][1] = 100;
    }
    
    while(!q.empty()) {
        Node now = q.top(); q.pop();                
        if(now.x == len - 1 && now.y == len - 1)
            return result[now.x][now.y][now.d];        
        int cost = now.s * 100 + now.c * 500;
        if(result[now.x][now.y][now.d] < cost) continue;
        
        for(int i = now.d - 1; i <= now.d + 1; i++) {
            int dir = (4 + i) % 4;
            int nx = now.x + dirs[dir][0];        
            int ny = now.y + dirs[dir][1];
            
            if(nx < 0 || ny < 0 || nx >= len || ny >= len) continue;
            if(board[nx][ny] == 1) continue;
            
            if(now.d == dir && result[nx][ny][dir] >= cost + 100) {
                result[nx][ny][dir] = cost + 100;
                q.push({nx, ny, dir, now.s + 1, now.c});
            } else if(now.d != dir && result[nx][ny][dir] >= cost + 600) {
                result[nx][ny][dir] = cost + 600;
                q.push({nx, ny, dir, now.s + 1, now.c + 1});
            }
        }
    }
}