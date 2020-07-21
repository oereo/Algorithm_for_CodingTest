#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct Pos {
    int row;
    int col;
} Pos;
typedef struct DistPos {
    int distance;
    Pos pos;
} DistPos;
typedef struct SharkInfo {
    Pos pos;
    int size; 
} SharkInfo;

int N;
vector<vector<int> > map;
vector<vector<bool> > visited;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
SharkInfo info; 

void getInput() {
    cin >> N;
    map.assign(N+2, vector<int>(N+2, -1));
    visited.assign(N+2, vector<bool>(N+2, false));

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                info = {{i, j}, 2};
            }
        }
    }
}
void initVisited() {
    visited.assign(N+2, vector<bool>(N+2, false));
}

DistPos selectFish() {
    DistPos ret = {1000*N, {4*N, 4*N}};
    queue<DistPos> q;
    q.push({0, info.pos});
    visited[info.pos.row][info.pos.col] = true;
    while(!q.empty()) {
        DistPos here = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            Pos next = {here.pos.row + dr[i], here.pos.col + dc[i]};
            if(map[next.row][next.col] != -1 && !visited[next.row][next.col] && map[next.row][next.col] <= info.size && here.distance+1 <= ret.distance) {
                if(map[next.row][next.col] && map[next.row][next.col] < info.size) {
                    if(next.row < ret.pos.row) {
                        ret = {here.distance+1, next};
                    } else if(next.row == ret.pos.row) {
                        if(next.col < ret.pos.col) {
                            ret = {here.distance+1, next};
                        }
                    }
                }
                else {
                    q.push({here.distance + 1, next});
                    visited[next.row][next.col] = true;
                }
            }
        }
    }

    return ret;
}

void solution() {
    int fishNum = 0;
    int totalTime = 0;
    DistPos eatenFish;
    while (true) {
        eatenFish = selectFish();
        if(eatenFish.distance == 1000*N) {
            break;
        }
        initVisited();

        map[info.pos.row][info.pos.col] = 0;
        info.pos = eatenFish.pos;
        map[info.pos.row][info.pos.col] = 9;

        totalTime += eatenFish.distance;
        fishNum += 1;
        if(fishNum == info.size) {
            info.size += 1;
            fishNum = 0;
        }
    }

    cout << totalTime;
}

int main() {
    getInput();
    solution();
    return 0;
}