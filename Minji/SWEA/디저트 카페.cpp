#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, MAX, startX, startY;
int map[20][20];
int dir[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
vector<int> temp;

void DFS(int x, int y, int d)
{
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];

    if (d == 3 && nx == startX && ny == startY)
    {
        int len = temp.size();
        if (MAX < len)
            MAX = len;
        return;
    }

    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        return;
    if (find(temp.begin(), temp.end(), map[nx][ny]) != temp.end())
        return;

    temp.push_back(map[nx][ny]);
    if (d == 3)
    {
        DFS(nx, ny, d);
    }
    else
    {
        DFS(nx, ny, d);
        DFS(nx, ny, d + 1);
    }
    temp.pop_back();
    return;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
        }

        MAX = -1;
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 1; j < N - 1; j++)
            {
                temp.clear();
                temp.push_back(map[i][j]);
                startX = i, startY = j;
                DFS(i, j, 0);
            }
        }
        cout << "#" << test_case << " " << MAX << endl;
    }
    return 0;
}