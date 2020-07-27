#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> choice;
vector<vector<int>> distances;
int MIN;
int stair[2][3];

void solution(int n)
{
    vector<int> stair1;
    vector<int> stair2;
    for (int i = 0; i < n; i++)
    {
        if (choice[i] == 0)
            stair1.push_back(distances[0][i]);
        else
            stair2.push_back(distances[1][i]);
    }

    sort(stair1.begin(), stair1.end());
    sort(stair2.begin(), stair2.end());

    int len1 = stair1.size();
    int len2 = stair2.size();
    for (int i = 0; i < len1; i++)
    {
        if (i - 3 < 0)
            continue;
        if (stair1[i] < stair1[i - 3] + stair[0][2])
            stair1[i] = stair1[i - 3] + stair[0][2];
    }

    for (int i = 0; i < len2; i++)
    {
        if (i - 3 < 0)
            continue;
        if (stair2[i] < stair2[i - 3] + stair[1][2])
            stair2[i] = stair2[i - 3] + stair[1][2];
    }

    int result = 0;
    if (len1 != 0)
        result = stair1.back() + stair[0][2] + 1;
    if (len2 != 0 && result < stair2.back() + stair[1][2] + 1)
        result = stair2.back() + stair[1][2] + 1;

    if (MIN > result)
        MIN = result;
}

void dfs(int n)
{
    if (choice.size() == n)
    {
        solution(n);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        choice.push_back(i);
        dfs(n);
        choice.pop_back();
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T, N, cnt, n;
    vector<vector<int>> map;
    vector<pair<int, int>> people;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        // 입력 받기
        cin >> N;
        map.assign(N, vector<int>(N));
        distances.assign(2, vector<int>(N));
        people.clear();
        MIN = 987654321;
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 1)
                {
                    people.push_back({i, j});
                }
                else if (map[i][j] != 0)
                {
                    stair[cnt][0] = i;
                    stair[cnt][1] = j;
                    stair[cnt][2] = map[i][j];
                    cnt++;
                }
            }
        }

        // 거리 구하기
        n = people.size();
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                distances[i][j] = abs(stair[i][0] - people[j].first) + abs(stair[i][1] - people[j].second);
            }
        }
        dfs(n);

        cout << "#" << test_case << " " << MIN << "\n";
    }
    return 0;
}