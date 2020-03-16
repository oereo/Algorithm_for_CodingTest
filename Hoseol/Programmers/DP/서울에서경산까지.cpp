#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001];
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    int len =travel.size();
    dp[0][travel[0][0]]=travel[0][1];
    dp[0][travel[0][2]]=travel[0][3];
    int ans=0;
    for(int i=1;i<len;i++)
    {
        for(int time=0;time<=K;time++)
        {
             if(dp[i-1][time] != 0){
            if(time+travel[i][0]<=K)
            {
                dp[i][time+travel[i][0]]=max(dp[i][time+travel[i][0]],dp[i-1][time]+travel[i][1]);
                ans=max(ans,dp[i][time+travel[i][0]]);
            }
            if(time+travel[i][2]<=K)
            {
                dp[i][time+travel[i][2]]=max(dp[i][time+travel[i][2]],dp[i-1][time]+travel[i][3]);
                ans=max(ans,dp[i][time+travel[i][2]]);
            }
        }
        }
    }
    return ans;
}