#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

string solution(int m, int n, vector<string> board)
{
    // map에 문자와 위치 저장
    map<char, pair<int, int>> dic;
    set<char> alphabet;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != '*' && board[i][j] != '.')
            {
                dic[board[i][j]] = {i, j};
                alphabet.insert(board[i][j]);
            }
        }
    }
    int len = alphabet.size();

    // BFS
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<vector<int>> q; //  i, x, y, dir, count
    string answer = "";
    while (1)
    {
        int before = answer.size();
        for (auto it = alphabet.begin(); it != alphabet.end(); it++)
        {
            q.push({*it, dic[*it].first, dic[*it].second, 0, 0});
            bool check = false;
            vector<vector<int>> visit(m, vector<int>(n));
            while (!q.empty())
            {
                char i = q.front()[0];
                int x = q.front()[1], y = q.front()[2], dir = q.front()[3], count = q.front()[4];
                q.pop();
                visit[x][y] = 1;
                for (int a = 0; a < 4; a++)
                {
                    int nx = x + dx[a], ny = y + dy[a];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || count > 2 || visit[nx][ny] == 1)
                        continue;
                    if (board[nx][ny] == i)
                    {
                        if (dir != a + 1 && count > 1)
                            continue;
                        while (!q.empty())
                        {
                            q.pop();
                        }
                        check = true;
                        board[nx][ny] = '.';
                        board[dic[i].first][dic[i].second] = '.';
                        answer += i;
                        alphabet.erase(it);
                        break;
                    }
                    if (board[nx][ny] == '.')
                    {
                        if (dir != a + 1)
                            q.push({i, nx, ny, a + 1, count + 1});
                        else
                            q.push({i, nx, ny, a + 1, count});
                    }
                }
            }
            if (check)
                break;
        }
        int after = answer.size();
        if (after == len)
            break;
        if (before == after)
            return "IMPOSSIBLE";
    }
    return answer;
}