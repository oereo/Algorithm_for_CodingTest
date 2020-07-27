#include <iostream>
#include <vector>

using namespace std;

struct CCTV
{
    int x;
    int y;
    int n;
};

int N, M, len;
int MIN = 987654321;
vector<vector<int>> map;
vector<vector<int>> copy_map;
vector<CCTV> cctvs;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int count()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void go(vector<int> dirs)
{
    for (int i = 0; i < len; i++)
    {
        int x = cctvs[i].x;
        int y = cctvs[i].y;
        int n = cctvs[i].n;
        switch (n)
        {
        case 1: // CCTV 1
            while (1)
            {
                x += dir[dirs[i]][0];
                y += dir[dirs[i]][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            break;
        case 2: // CCTV 2
            while (1)
            {
                x += dir[dirs[i]][0];
                y += dir[dirs[i]][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[(dirs[i] + 2) % 4][0];
                y += dir[(dirs[i] + 2) % 4][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            break;
        case 3: // CCTV 3
            while (1)
            {
                x += dir[dirs[i]][0];
                y += dir[dirs[i]][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[(dirs[i] + 3) % 4][0];
                y += dir[(dirs[i] + 3) % 4][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            break;
        case 4: // CCTV 4
            while (1)
            {
                x += dir[dirs[i]][0];
                y += dir[dirs[i]][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[(dirs[i] + 2) % 4][0];
                y += dir[(dirs[i] + 2) % 4][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[(dirs[i] + 3) % 4][0];
                y += dir[(dirs[i] + 3) % 4][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            break;
        case 5: // CCTV 5
            while (1)
            {
                x += dir[0][0];
                y += dir[0][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[1][0];
                y += dir[1][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[2][0];
                y += dir[2][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            x = cctvs[i].x;
            y = cctvs[i].y;
            while (1)
            {
                x += dir[3][0];
                y += dir[3][1];
                if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 6)
                    break;
                map[x][y] = n;
            }
            break;
        }
    }
}

void DFS(int cnt, vector<int> dirs)
{
    if (cnt == len)
    {
        go(dirs);
        int result = count();
        if (MIN > result)
            MIN = result;
        map = copy_map;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        dirs[cnt] = i;
        DFS(cnt + 1, dirs);
    }
}

int main()
{
    // 입력 받기
    cin >> N >> M;
    map.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
            {
                cctvs.push_back({i, j, map[i][j]});
            }
        }
    }
    copy_map = map;

    // 모든 방향 탐색하여 최소 사각 지대 구하기
    len = cctvs.size();
    vector<int> dirs(len);
    DFS(0, dirs);
    cout << MIN;
}