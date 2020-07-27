#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef struct Pos {
    int row;
    int col;
} Pos;

vector<vector<int> > initMap;
vector<vector<int> > runningMap;
vector<vector<bool> > visited;

vector<int> comb;
vector<Pos> vacantPos;
vector<Pos> virusPos;
int N, M;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void printMap();

void getInput() {
    int zeroCount = 0;
    cin >> N >> M;
    initMap.assign(N+2, vector<int>(M+2, -1));
    visited.assign(N+2, vector<bool>(M+2, false));

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> initMap[i][j];
            if(initMap[i][j] == 2) {
                virusPos.push_back(Pos{i,j});
            }
            if(initMap[i][j] == 0) {
                zeroCount++;
                vacantPos.push_back(Pos{i,j});
            }
        }
    }
    runningMap = initMap;
    comb.assign(zeroCount, 0);
    for(int i=0; i<3; i++) {
        comb[i] = 1;
    }
    sort(comb.begin(), comb.end());
}

void setWalls() {
    for(int i = 0; i < comb.size(); i++) {
        if(comb[i] == 1) {
            runningMap[vacantPos[i].row][vacantPos[i].col] = 1;
        }
    }
}

void spreadOutVirus() {
    queue<Pos> q;
    for(int i=0; i<virusPos.size(); i++) {
        q.push(virusPos[i]);
        visited[virusPos[i].row][virusPos[i].col] = true;
    }

    while(!q.empty()) {
        Pos here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            Pos next = {here.row + dr[i], here.col + dc[i]};
            if(!visited[next.row][next.col] && runningMap[next.row][next.col] == 0) {
                q.push(next);
                visited[next.row][next.col] = true;
                runningMap[next.row][next.col] = 2;
            }
        }
    }
}

int countSafetyZone() {
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(runningMap[i][j] == 0) {
                ret++;
            }
        }
    }
    return ret;
}

void solution() {
    int maxSafetyZone = -1;
    do {
        setWalls();
        spreadOutVirus();
        int safetyZone = countSafetyZone();
        if(safetyZone > maxSafetyZone) {
            maxSafetyZone = safetyZone;
        }
        runningMap = initMap;
        visited.assign(N+2, vector<bool>(M+2, false));
    } while(next_permutation(comb.begin(), comb.end()));

    cout << maxSafetyZone;
}

int main() {
    getInput();
    solution();
}