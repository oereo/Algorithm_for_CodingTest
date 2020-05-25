#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입력 받기
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> map(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char a;
            cin >> a;
            if (a == 'W')
                map[i][j] = 1;
        }
    }

    // 바꿀 수 있는 곳 찾기 : 인접한 곳이 같은 색일 때 가능
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int answer = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool check = true;
            for (int a = 0; a < 4; a++)
            {
                int nx = i + dir[a][0];
                int ny = j + dir[a][1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (map[nx][ny] != map[i][j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                answer = answer * 2 % 1000000007;
        }
    }

    if (answer == 1)
        cout << 0;
    else
        cout << answer;
}