#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visit;
int N, K, answer;
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void DFS(int x, int y, int cnt, bool check)
{
    int nx, ny;
    int now = map[x][y];
    for (int i = 0; i < 4; i++)
    {
        nx = x + dirs[i][0];
        ny = y + dirs[i][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (visit[nx][ny])
            continue;

        if (now > map[nx][ny])
        {
            visit[nx][ny] = 1;
            DFS(nx, ny, cnt + 1, check);
            visit[nx][ny] = 0;
        }
        else if (!check && now > map[nx][ny] - K)
        {
            // 주의 : K만큼 깎는게 아니라, now - 1의 높이로 깎아줘야 더 긴 등산로를 만들 수 있음
            // 그렇지 않으면 49/51개만 통과함
            visit[nx][ny] = 1;
            int temp = map[nx][ny];
            map[nx][ny] = now - 1;
            DFS(nx, ny, cnt + 1, !check);
            map[nx][ny] = temp;
            visit[nx][ny] = 0;
        }
        else
        {
            if (answer < cnt)
                answer = cnt;
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T, MAX;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        // 입력 받기 & 가장 높은 봉우리 찾기
        cin >> N >> K;
        map.assign(N, vector<int>(N));
        visit.assign(N, vector<int>(N));
        vector<pair<int, int>> highest;
        MAX = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (MAX < map[i][j])
                {
                    MAX = map[i][j];
                    highest.clear();
                    highest.push_back({i, j});
                }
                else if (MAX == map[i][j])
                {
                    highest.push_back({i, j});
                }
            }
        }

        // 가장 긴 등산로 찾기
        answer = 1;
        for (auto i : highest)
        {
            bool check = false;
            visit[i.first][i.second] = 1;
            DFS(i.first, i.second, 1, check);
            visit[i.first][i.second] = 0;
        }
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}