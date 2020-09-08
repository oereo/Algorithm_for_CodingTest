#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<vector<int>>> map;

bool check(int x, int y, int a)
{
    if (a == 0)
    { // 기둥
        if (!y || (y - 1 >= 0 && map[0][x][y - 1]) || map[1][x][y] || (x - 1 >= 0 && map[1][x - 1][y]))
            return true;
    }
    else
    { // 보
        if ((y - 1 >= 0 && map[0][x][y - 1]) || (y - 1 >= 0 && map[0][x + 1][y - 1])
        || (x - 1 >= 0 && map[1][x - 1][y] && map[1][x + 1][y]))
            return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    map.assign(2, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    int len = build_frame.size();
    int x, y, a, b;
    for (int i = 0; i < len; i++)
    {
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        if (b == 0)
        { // 삭제
            map[a][x][y] = 0;
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        if (map[a][x][y] == 1)
                            break;
                        if (map[k][i][j] == 1 && !check(i, j, k))
                            map[a][x][y] = 1;
                    }
                }
            }
        }
        else
        { // 설치
            if (check(x, y, a))
                map[a][x][y] = 1;
        }
    }

    // 정답 벡터에 저장
    vector<vector<int>> answer;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (map[k][i][j] == 1)
                    answer.push_back({i, j, k});
            }
        }
    }
    return answer;
}