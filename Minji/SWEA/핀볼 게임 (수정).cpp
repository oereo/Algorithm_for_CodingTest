#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
int N, MAX, x, y, nx, ny, cnt;
int map[100][100];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<pair<int, int>> wormhole[5];

int change(int a, int d) {
    int new_dir[4] = { 2,2,-1,1 };
    d = (d + new_dir[(d + 5 - a) % 4] + 4) % 4;
    return d;
}
 
void go(int x, int y, int d) {
    nx = x, ny = y;
    cnt = 0;
    bool first = true;
    bool black = false;
    while (1) {
        if (black || (!first && x == nx && y == ny)) break;
        first = false;
        nx += dir[d][0];
        ny += dir[d][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            cnt *= 2;
            cnt++;
            break;
        }
        switch (map[nx][ny]){
        case -1:
            black = true;
            break;
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            d = change(map[nx][ny], d);
            cnt++;
            break;
        case 5:
            cnt *= 2;
            cnt++;
            black = true;
            break;
        default:
            int num = map[nx][ny] - 6;
            if (wormhole[num][0].first == nx && wormhole[num][0].second == ny) {
                nx = wormhole[num][1].first;
                ny = wormhole[num][1].second;
            }
            else {
                nx = wormhole[num][0].first;
                ny = wormhole[num][0].second;
            }
            break;
        }
    }
    if (MAX < cnt)
        MAX = cnt;
}
 
int main(int argc, char** argv)
{
    int test_case, i, j, k;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        // 입력 받기
        cin >> N;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < 5; i++)
            wormhole[i].clear();        
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> map[i][j];
                // 웜홀 위치 저장
                if(map[i][j] > 5) {
                    wormhole[map[i][j] - 6].push_back({i, j});
                }
            }
        }
 
        // 핀볼 게임
        MAX = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < 4; k++)  {
                    if(map[i][j] == 0)
                        go(i, j, k);
                }
            }
        }
        cout << "#" << test_case << " " << MAX << '\n';
    }
    return 0;
}