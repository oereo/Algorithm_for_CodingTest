#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct location
{
    int r, c, l;
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<int> go_dirs;
queue<location> q;
int cnt, N, M, R, C, L;

void go(int x, int y, int l)
{
    int nx, ny, next;
    int len = go_dirs.size();
    for (int i = 0; i < len; i++)
    {
        nx = x + dir[go_dirs[i]][0];
        ny = y + dir[go_dirs[i]][1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        next = map[nx][ny];
        bool check = true;

        switch (go_dirs[i])
        {
        case 0:
            if (next == 0 || next == 3 || next == 4 || next == 7 || visit[nx][ny] == 1)
                check = false;
            break;
        case 1:
            if (next == 0 || next == 2 || next == 4 || next == 5 || visit[nx][ny] == 1)
                check = false;
            break;
        case 2:
            if (next == 0 || next == 3 || next == 5 || next == 6 || visit[nx][ny] == 1)
                check = false;
            break;
        case 3:
            if (next == 0 || next == 2 || next == 6 || next == 7 || visit[nx][ny] == 1)
                check = false;
            break;
        }

        if (check)
        {
            cnt++;
            visit[nx][ny] = 1;
            q.push({nx, ny, l - 1});
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> R >> C >> L;
        map.assign(N, vector<int>(M));
        visit.assign(N, vector<bool>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[i][j];
            }
        }
        q.push({R, C, L - 1});
        cnt = 1;
        visit[R][C] = 1;
        while (!q.empty())
        {
            location now = {q.front().r, q.front().c, q.front().l};
            q.pop();
            if (now.l == 0)
                continue;
            switch (map[now.r][now.c])
            {
            case 1:
                go_dirs = {0, 1, 2, 3};
                break;
            case 2:
                go_dirs = {0, 2};
                break;
            case 3:
                go_dirs = {1, 3};
                break;
            case 4:
                go_dirs = {0, 1};
                break;
            case 5:
                go_dirs = {1, 2};
                break;
            case 6:
                go_dirs = {2, 3};
                break;
            case 7:
                go_dirs = {0, 3};
                break;
            }
            go(now.r, now.c, now.l);
        }
        cout << "#" << test_case << " " << cnt << endl;
    }
    return 0;
}