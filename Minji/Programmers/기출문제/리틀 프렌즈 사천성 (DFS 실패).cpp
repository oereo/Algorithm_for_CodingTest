// Test Case만 통과

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> board2;
vector<vector<int>> visit;
int m2, n2;
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool DFS(char a, int x, int y, int dir, int count)
{
    if (count > 0 && board2[x][y] == a)
    {
        board2[x][y] = '.';
        return true;
    }
    if (count > 2)
        return false;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx < 0 || nx >= m2 || ny < 0 || ny >= n2)
            continue;
        if (visit[nx][ny] == 0 && (board2[nx][ny] == a || board2[nx][ny] == '.'))
        {
            visit[nx][ny] = 1;
            if (dir == i + 1)
            { // 같은 방향이면
                if (DFS(a, nx, ny, i + 1, count))
                    return true;
            }
            else
            {
                if (DFS(a, nx, ny, i + 1, count + 1))
                    return true;
            }
            visit[nx][ny] = 0;
        }
    }
    return false;
}

string solution(int m, int n, vector<string> board)
{
    // 알파벳 저장
    vector<char> a;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != '*' && board[i][j] != '.' &&
                find(a.begin(), a.end(), board[i][j]) == a.end())
            {
                a.push_back(board[i][j]);
            }
        }
    }
    sort(a.begin(), a.end());

    // 타일 제거하기
    board2 = board, n2 = n, m2 = m;
    int idx = 0;
    int len = a.size();
    string answer = "";
    while (1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[idx] == board2[i][j])
                {
                    visit.assign(m, vector<int>(n));
                    visit[i][j] = 1;
                    if (DFS(a[idx], i, j, 0, 0))
                    {
                        board2[i][j] = '.';
                        answer += a[idx];
                        idx = 0, i = 0, j = 0;
                        break;
                    }
                    visit[i][j] = 0;
                }
            }
        }
        idx++;
        if (idx == len)
            break;
    }
    if (answer.size() == len)
        return answer;
    return "IMPOSSIBLE";
}