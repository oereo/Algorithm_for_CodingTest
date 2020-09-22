#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int R,C,T;
int map[51][51];
int map_cpy[51][51];
int dir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
int cleaner_row;

void getInput() {
    cin >> R >> C >> T; 
    memset(map, 0, sizeof(map));
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                cleaner_row = i;
            }
        }
    }
}

bool isCleanerPos(int r, int c) {
    return (r==cleaner_row && c==1) || (r==cleaner_row-1 && c==1);
}
bool isValidPos(int r, int c) {
    return r>=1 && r<=R && c>=1 && c<=C;
}
bool isCleanerUpper(int r, int c) {
    return r<=cleaner_row-1;
}
bool isCleanerLower(int r, int c) {
    return r>=cleaner_row;
}
bool isInCleanerRange(int r, int c) {
    return (r==cleaner_row-1 || r==cleaner_row || r==R || r==1 || c==1 || c==C);
}
bool goLeft(int r, int c) {
    return (r==1 && c!=1) || (r==R && c!=1);
}
bool goRight(int r, int c) {
    return (r==cleaner_row && c!=C) || (r==cleaner_row-1 && c!=C);
}
bool goUp(int r, int c) {
    return (isCleanerLower(r,c) && c==1) || (isCleanerUpper(r,c) && c==C && r!=1);
}
bool goDown(int r, int c) {
    return (isCleanerLower(r,c) && c==C && r!=R) || (isCleanerUpper(r,c) && c==1);
}

void diffuse() {
    memset(map_cpy, 0, sizeof(map_cpy));
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(map[i][j] > 0) {
                int src = map[i][j];
                int diffuse_size = src / 5;
                int diffuse_dir = 0;
                for(int d=0; d<4; d++) {
                    int nr = i + dir[d][0], nc = j + dir[d][1];
                    if(isValidPos(nr,nc) && !isCleanerPos(nr,nc)) {
                        map_cpy[nr][nc] += diffuse_size;
                        diffuse_dir += 1;
                    }
                }

                map_cpy[i][j] += src - diffuse_dir*diffuse_size;
            }
            else map_cpy[i][j] += map[i][j];
        }
    }

    memcpy(map, map_cpy, sizeof(map));
}

void runCleaner() {
    memset(map_cpy, 0, sizeof(map_cpy));
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            int size = map[i][j];
            if(isInCleanerRange(i,j) && !isCleanerPos(i,j)) {
                if(goLeft(i,j)) {
                    if(map[i][j-1] != -1) map_cpy[i][j-1] = size;
                }
                else if(goRight(i,j)) {
                    if(map[i][j+1] != -1) map_cpy[i][j+1] = size; 
                }
                else if(goDown(i,j)) {
                    if(map[i+1][j] != -1) map_cpy[i+1][j] = size;
                }
                else if(goUp(i,j)) {
                    if(map[i-1][j] != -1) map_cpy[i-1][j] = size;
                }
            }
            else map_cpy[i][j] = size;
        }
    }
    memcpy(map, map_cpy, sizeof(map));
}

void solution() {
    for(int t=0; t<T; t++) {
        diffuse();
        runCleaner();
    }

    int ans = 0;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(map[i][j] > 0) {
                ans += map[i][j];
            }
        }
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
    return 0;
}