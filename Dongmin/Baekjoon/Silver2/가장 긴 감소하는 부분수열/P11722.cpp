#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int ans;
int N;
int sequence[1000];
int dp[1000];

void getInput() {
    ans=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> sequence[i];
    }

    memset(dp,-1,sizeof(dp));
}

int lis(int start)
{
    int& ret=dp[start];
    if(ret!=-1) return ret;
    ret=1;
    for(int next=start-1; next>=0; next--)
    {
        if(sequence[next]>sequence[start])
        {
            ret = max(ret,lis(next)+1);
        }
    }
    return ret;
}

void solution() {
    for(int i=N-1; i>=0; i--)
    {
        ans = max(ans, lis(i));
    }
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}