#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
    // visit 벡터
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visit(n, vector<int>(m));
    visit[0][0] = 1;

    // BFS
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == n - 1 && y == m - 1)
            return visit[n - 1][m - 1];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m)
                continue;
            if (visit[x + dx[i]][y + dy[i]] == 0 && maps[x + dx[i]][y + dy[i]] == 1)
            {
                visit[x + dx[i]][y + dy[i]] = visit[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
    return -1;
}