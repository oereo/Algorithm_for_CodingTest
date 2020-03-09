#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[2001][2001];

void dp_clear(int a, int b)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            dp[i][j]=-1;
        }
    }

}
int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    int len1=left.size();
    int len2=right.size();
    dp_clear(len1,len2);
    dp[0][0]=0;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(dp[i][j]==-1) //예제에서의 3,1같은경우를 방지하기위해서.
            {
                continue;
            }
            if(right[j]<left[i]&&dp[i][j+1]<dp[i][j]+right[j])
            {
                dp[i][j+1]=dp[i][j]+right[j];
                answer=max(answer,dp[i][j+1]);
            }
             dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
             dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
    }
    return answer;
}