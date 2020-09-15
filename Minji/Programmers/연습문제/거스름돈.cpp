#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money)
{
    int len = money.size();
    vector<vector<int>> DP(len, vector<int>(n + 1));
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % money[0] == 0)
            DP[0][i] = 1;
    }

    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            DP[i][j] = DP[i - 1][j];
            if (j < money[i])
                continue;
            DP[i][j] += DP[i][j - money[i]];
            DP[i][j] %= 1000000007;
        }
    }

    return DP[len - 1][n];
}