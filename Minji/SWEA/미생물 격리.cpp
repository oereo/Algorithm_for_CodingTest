#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct cluster
{
    int x, y, m;
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(int argc, char **argv)
{
    int test_case;
    int T, N, M, K, x, y, k, d, total, nx, ny;
    cin >> T;
    int map[100][100][3];
    int copy_map[100][100][3];
    queue<cluster> q;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(map, 0, sizeof(map));
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> x >> y >> k >> d;
            map[x][y][0] = k;
            map[x][y][1] = d;
            q.push({x, y, 0});
        }

        total = 0;
        while (!q.empty())
        {
            int len = q.size();
            memset(copy_map, 0, sizeof(copy_map));
            for (int i = 0; i < len; i++)
            {
                cluster now = {q.front().x, q.front().y, q.front().m};
                k = map[now.x][now.y][0];
                d = map[now.x][now.y][1];
                q.pop();

                if (now.m == M)
                {
                    total += map[now.x][now.y][0];
                    continue;
                }

                nx = now.x + dir[d - 1][0];
                ny = now.y + dir[d - 1][1];

                if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1)
                { // 테두리 부분인 경우
                    k /= 2;
                    if (k == 0)
                        continue;
                    if (d == 1 || d == 3)
                        d++;
                    else
                        d--;
                }

                if (copy_map[nx][ny][0] == 0)
                { // 겹치지 않는 경우
                    copy_map[nx][ny][0] = k;
                    copy_map[nx][ny][1] = d;
                    q.push({nx, ny, now.m + 1});
                }
                else
                { // 겹치는 경우
                    if (copy_map[nx][ny][2] == 0)
                        copy_map[nx][ny][2] = copy_map[nx][ny][0];
                    if (copy_map[nx][ny][2] < k)
                    {
                        copy_map[nx][ny][2] = k;
                        copy_map[nx][ny][1] = d;
                    }
                    copy_map[nx][ny][0] += k;
                }
            }
            memcpy(map, copy_map, sizeof(map));
        }
        cout << "#" << test_case << " " << total << endl;
    }
    return 0;
}