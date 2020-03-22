#include <string>
#include <vector>
long long dp[2001]={0,1,2,};
using namespace std;
long long solution(int n) {
    long long answer = 0;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=1234567;
    }
    return dp[n];
}