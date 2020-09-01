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

int glis(int start)
{
    int& ret=dp[start];
    if(ret!=-1) return ret;
    ret=sequence[start];
    for(int next=start+1; next<N; next++)
    {
        if(sequence[next]>sequence[start])
        {
            ret = max(ret,sequence[start]+glis(next));
        }
    }
    return ret;
}

void solution() {
    for(int i=0; i<N; i++)
    {
        ans = max(ans, glis(i));
    }
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}