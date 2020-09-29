#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef struct Shift {
    int x,d,k;
} Shift;
int N,M,T;
int rings[51][51];
Shift shifts[50];

void getInput() {
    cin >> N >> M >> T;
    memset(rings, 0, sizeof(rings));
    memset(shifts, 0, sizeof(shifts));
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            cin >> rings[i][j];
        }
    }

    for(int i=0; i<T; i++) {
        cin >> shifts[i].x >> shifts[i].d >> shifts[i].k;
    }
}

void rotateClockwise(int ringnum, int k) {
    int temp[51];
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<M; i++) {
        int shifted = (i + k) % M;
        temp[shifted] = rings[ringnum][i];
    }

    memcpy(rings[ringnum], temp, sizeof(temp));
}
void rotateCounterClockwise(int ringnum, int k) {
    int temp[51];
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<M; i++) {
        int shifted = (i - k) % M;
        while(shifted < 0 || shifted >= M) shifted += M;
        temp[shifted] = rings[ringnum][i];
    }
    memcpy(rings[ringnum], temp, sizeof(temp));
}
bool isValidPos(int i, int j) {
    return i>=1 && i<=N && j>=0 && j<M;
}
int removeSame() {
    int temp[51][51];
    memset(temp, 0, sizeof(temp));
    
    int removed = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            int dir[4][2] = { { i, (j-1 == -1) ? M-1:j-1 },
                              { i, (j+1 == M) ? 0:j+1 },
                              { i-1, j },
                              { i+1, j } };
            for(int k=0; k<4; k++) {
                if(isValidPos(dir[k][0], dir[k][1])) {
                    if(rings[i][j] && rings[i][j] == rings[dir[k][0]][dir[k][1]]) {
                        removed += 1;
                        temp[i][j] = 0;
                        break;
                    }
                    else temp[i][j] = rings[i][j];
                }
            }
        }
    }

    memcpy(rings, temp, sizeof(rings));
    return removed;
}
void averageProcess() {
    int totalnum = 0;
    int sum = 0;
    float avg;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            if(rings[i][j]) {
                totalnum += 1;
                sum += rings[i][j];
            }
        }
    }

    avg = (float)sum / totalnum;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            if(rings[i][j]) {
                if(rings[i][j] > avg) {
                    rings[i][j] -= 1;
                }
                else if(rings[i][j] < avg) {
                    rings[i][j] += 1;
                }
            }
        }
    }
}

void solution() {
    for(int i=0; i<T; i++) {
        for(int j=shifts[i].x; j<=N; j += shifts[i].x) {
            if(shifts[i].d == 0) {
                rotateClockwise(j, shifts[i].k);
            } else {
                rotateCounterClockwise(j, shifts[i].k);
            }
        }

        int removed = removeSame();
        if(removed == 0) {
            averageProcess();
        }
    }

    int sum=0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            sum += rings[i][j];
        }
    }
    printf("%d", sum);
}

int main() {
    getInput();
    solution();
    return 0;
}