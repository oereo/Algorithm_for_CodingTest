#include <vector>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map)
{
    // 방향에 따라 값을 따로 저장해야 함
    vector<vector<int>> V(m + 1, vector<int>(n + 1)); // 아래로 이동
    vector<vector<int>> H(m + 1, vector<int>(n + 1)); // 오른쪽으로 이동
    V[1][1] = 1, H[1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city_map[i - 1][j - 1] == 0)
            {
                V[i][j] = (V[i][j] + V[i - 1][j] + H[i][j - 1]) % MOD;
                H[i][j] = (H[i][j] + V[i - 1][j] + H[i][j - 1]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 1)
            {
                V[i][j] = 0;
                H[i][j] = 0;
            }
            else
            {
                V[i][j] = V[i - 1][j];
                H[i][j] = H[i][j - 1];
            }
        }
    }
    return H[m][n];
}