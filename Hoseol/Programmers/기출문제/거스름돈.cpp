#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001]={1,};
int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(),money.end());
    int len =money.size();
    for(int i=0;i<len;i++)
    {   int number=money[i];
        for(int j=1;j<=n;j++)
        {
            if(j>=number){
                dp[j]+=dp[j-number];
                dp[j]%=1000000007;
            }
        }
    }
    return dp[n];
}