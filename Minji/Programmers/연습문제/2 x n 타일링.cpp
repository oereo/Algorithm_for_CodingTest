#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<int> DP(n + 1);
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;
    }
    return DP[n];
}