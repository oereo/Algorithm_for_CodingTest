#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int DP[] = {1, 2};
    for (int i = 2; i < n; i++)
    {
        DP[0] = (DP[0] + DP[1]) % 1234567;
        swap(DP[0], DP[1]);
    }
    return DP[1];
}