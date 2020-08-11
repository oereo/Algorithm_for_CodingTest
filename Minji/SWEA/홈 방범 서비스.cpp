#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    int test_case, i, j, k, a, b, c, cost, count, MAX;
    int T, N, M;
    bool map[20][20];
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        // 입력 받기
        cin >> N >> M;
        memset(map, 0, sizeof(map));
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
        }

        // 최대 개수 구하기
        MAX = 0;
        for (k = 0; k <= N; k++)
        {                                     // k = 0일 때, K = 1, K가 N+1까지 되어야 map의 모든 칸을 포함할 수 있음
            cost = k * k + (k + 1) * (k + 1); // 운영 비용
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    // 서비스 영역
                    c = 0;
                    count = 0;
                    for (a = i - k; a <= i + k; a++)
                    {
                        for (b = j - c; b <= j + c; b++)
                        {
                            if (a < 0 || a >= N || b < 0 || b >= N)
                                continue;
                            if (map[a][b])
                                count++;
                        }
                        if (a < i)
                            c++;
                        else
                            c--;
                    }

                    if (count * M - cost >= 0 && MAX < count)
                        MAX = count;
                }
            }
        }

        cout << "#" << test_case << " " << MAX << '\n';
    }
    return 0;
}