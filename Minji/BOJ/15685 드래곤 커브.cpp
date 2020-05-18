#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입력 받기
    int N;
    cin >> N;
    vector<vector<int>> dragon(N, vector<int>(4));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> dragon[i][j];
        }
    }

    // 드래곤 커브 그리기
    int map[101][101] = {0};
    int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    for (int i = 0; i < N; i++)
    {
        int y = dragon[i][0];
        int x = dragon[i][1];
        int d = dragon[i][2];
        int g = dragon[i][3];
        map[x][y] = 1;
        vector<int> DP;
        DP.push_back(d);
        for (int j = 0; j < g; j++)
        {
            vector<int> temp = DP;
            reverse(temp.begin(), temp.end());
            for (int t = 0; t < temp.size(); t++)
            {
                temp[t] = (temp[t] + 1) % 4;
                DP.push_back(temp[t]);
            }
        }

        for (int k = 0; k < DP.size(); k++)
        {
            int dx = dir[DP[k]][0];
            int dy = dir[DP[k]][1];
            x = x + dx;
            y = y + dy;
            map[x][y] = 1;
        }
    }

    // 정사각형 개수 찾기
    int answer = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1)
            {
                if (map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
                    answer++;
            }
        }
    }

    cout << answer;
}