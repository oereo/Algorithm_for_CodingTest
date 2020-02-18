#include <string>
#include <vector>

using namespace std;
struct rect{
   long w;
    long h; 
};
rect dp[100];
long long solution(int N) {
    dp[1].w=1;
    dp[1].h=2;
    for(int i=2;i<=N-1;i++)
    {
        dp[i].w=dp[i-1].h;
        dp[i].h=dp[i-1].w+dp[i-1].h;
    }
    
    
    long long answer = (dp[N-1].w+dp[N-1].h)*2;
    return answer;
}