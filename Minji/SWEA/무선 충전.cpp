#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case, i, j, a, b, c, total, result;
    int T, M, A, X, Y, C, P;
    int x1, y1, x2, y2, len1, len2, MAX;
    int map[11][11][9];
    int user1[101];
    int user2[101];
    vector<int> BC1;
    vector<int> BC2;
    int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {

        // 입력 받기 & map에 충전 범위 표시
        memset(user1, 0, sizeof(user1));
        memset(user2, 0, sizeof(user2));
        memset(map, 0, sizeof(map));

        cin >> M >> A;
        for (i = 1; i <= M; i++)
        {
            cin >> user1[i];
        }
        for (i = 1; i <= M; i++)
        {
            cin >> user2[i];
        }

        for (i = 1; i <= A; i++)
        {
            cin >> Y >> X >> C >> P;
            c = 0;
            for (a = X - C; a <= X + C; a++)
            {
                for (b = Y - c; b <= Y + c; b++)
                {
                    if (a < 1 || a > 10 || b < 1 || b > 10)
                        continue;
                    map[a][b][i] = P;
                }
                if (a < X)
                    c++;
                else
                    c--;
            }
        }

        // 사람 이동 & 최대 충전량 구하기
        x1 = 1, y1 = 1, x2 = 10, y2 = 10, total = 0;
        for (i = 0; i <= M; i++)
        {
            x1 += dir[user1[i]][0], y1 += dir[user1[i]][1];
            x2 += dir[user2[i]][0], y2 += dir[user2[i]][1];
            for (j = 1; j <= A; j++)
            {
                if (map[x1][y1][j] != 0)
                    BC1.push_back(j);
                if (map[x2][y2][j] != 0)
                    BC2.push_back(j);
            }
            if (BC1.empty())
                BC1.push_back(0);
            if (BC2.empty())
                BC2.push_back(0);
            len1 = BC1.size();
            len2 = BC2.size();

            // 최대 충전량 구하기
            MAX = 0;
            for (a = 0; a < len1; a++)
            {
                for (b = 0; b < len2; b++)
                {
                    result = 0;
                    if (BC1[a] == BC2[b])
                        result = map[x1][y1][BC1[a]];
                    else
                    {
                        result += map[x1][y1][BC1[a]];
                        result += map[x2][y2][BC2[b]];
                    }
                    if (MAX < result)
                        MAX = result;
                }
            }

            total += MAX;

            BC1.clear();
            BC2.clear();
        }

        cout << "#" << test_case << " " << total << endl;
    }
    return 0;
}