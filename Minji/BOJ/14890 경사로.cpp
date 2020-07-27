#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입력 받기
    int N, L;
    cin >> N >> L;
    vector<vector<int>> map(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // 가로 탐색
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        bool check = true;
        int now = map[i][0];
        int cnt = 1;
        for (int j = 1; j < N; j++)
        {
            if (now == map[i][j]) // 높이가 같을 때
                cnt++;
            else if (map[i][j] - now == 1)
            { // 높이 차이 1
                if (cnt >= L)
                {
                    cnt = 1;
                    now = map[i][j];
                }
                else
                {
                    check = false;
                    break;
                }
            }
            else if (map[i][j] - now == -1)
            { // 높이 차이 -1
                now = map[i][j];
                cnt = 0;
                for (int a = 1; a < L; a++)
                {
                    j++;
                    if (j >= N || now != map[i][j])
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }
            else
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            answer++;
        }
    }

    // 세로 탐색
    for (int i = 0; i < N; i++)
    {
        bool check = true;
        int now = map[0][i];
        int cnt = 1;
        for (int j = 1; j < N; j++)
        {
            if (now == map[j][i]) // 높이가 같을 때
                cnt++;
            else if (map[j][i] - now == 1)
            { // 높이 차이 1
                if (cnt >= L)
                {
                    cnt = 1;
                    now = map[j][i];
                }
                else
                {
                    check = false;
                    break;
                }
            }
            else if (map[j][i] - now == -1)
            { // 높이 차이 -1
                now = map[j][i];
                cnt = 0;
                for (int a = 1; a < L; a++)
                {
                    j++;
                    if (j >= N || now != map[j][i])
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }

            else
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            answer++;
        }
    }

    cout << answer;
}