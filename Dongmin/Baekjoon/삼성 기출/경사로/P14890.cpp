#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int N, L;
vector<vector<int> > map;
void getInput() {
    cin >> N >> L;
    map.assign(N, vector<int>(N, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}

void checkRowRoad(int row, int& cnt) {
    vector<bool> established;
    int prev_height = map[row][0];
    int continuous_lower_left = 0, continuous_lower_right = -1000;
    established.assign(N, false);

    for(int c=0; c<N; c++) {
        if(map[row][c] != prev_height) {
            if(continuous_lower_right > 0 && continuous_lower_right < L) {
                return;
            }

            int diff = abs(map[row][c] - prev_height);
            if(diff > 1) {
                return;
            }
            else if(map[row][c] > prev_height) {
                if(continuous_lower_left >= L) {
                    prev_height = map[row][c];
                    continuous_lower_left = 1;

                    for(int pos = c-1; pos >= c-L; pos--) {
                        if(!established[pos]) established[pos] = true;
                        else return;
                    }
                }
                else {
                    return;
                }
            }
            else {
                prev_height = map[row][c];
                continuous_lower_left = 1;
                continuous_lower_right = 1;
                for(int pos = c; pos <= c+L-1; pos++) {
                    if(!established[pos]) established[pos] = true;
                    else return;
                }
            }
        } else {
            continuous_lower_left += 1;
            continuous_lower_right += 1;
        }
    }

    if(continuous_lower_right > 0 && continuous_lower_right < L) {
        return;
    }
    cnt += 1;
}

void checkColRoad(int col, int& cnt) {
    vector<bool> established;
    int prev_height = map[0][col];
    int continuous_lower_left = 0, continuous_lower_right = -1000;
    established.assign(N, false);

    for(int r=0; r<N; r++) {
        if(map[r][col] != prev_height) {
            if(continuous_lower_right > 0 && continuous_lower_right < L) {
                return;
            }

            int diff = abs(map[r][col] - prev_height);
            if(diff > 1) {
                return;
            }
            else if(map[r][col] > prev_height) {
                if(continuous_lower_left >= L) {
                    prev_height = map[r][col];
                    continuous_lower_left = 1;

                    for(int pos = r-1; pos >= r-L; pos--) {
                        if(!established[pos]) established[pos] = true;
                        else return;
                    }                    
                }
                else {
                    return;
                }
            }
            else {
                prev_height = map[r][col];
                continuous_lower_left = 1;
                continuous_lower_right = 1;

                for(int pos = r; pos <= r+L-1; pos++) {
                    if(!established[pos]) established[pos] = true;
                    else return;
                }
            }
        } else {
            continuous_lower_left += 1;
            continuous_lower_right += 1;
        }
    }

    if(continuous_lower_right > 0 && continuous_lower_right < L) {
        return;
    }
    cnt += 1;
}

void solution() {
    int ans = 0;
    for(int i=0; i<N; i++) {
        checkRowRoad(i, ans);
        checkColRoad(i, ans);
    }
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}