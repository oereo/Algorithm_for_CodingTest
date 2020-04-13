#include <string>
#include <vector>

using namespace std;

struct stair{
    int a = 0; // 한칸
    int b = 0; // 두칸
};

stair dp[2002];

long long solution(int n) {
    long long answer = 0;

    dp[1].a = 1;
    dp[1].b = 0;
    dp[2].a = 1;
    dp[2].b = 1;

    for(int i = 3; i<=n; i++){
        dp[i].a = dp[i-1].a+dp[i-1].b;
        dp[i].a = dp[i].a%1234567;
        dp[i].b = dp[i-2].a+dp[i-2].b;
        dp[i].b = dp[i].b%1234567;
    }

    answer = dp[n].a+dp[n].b;
    answer = answer%1234567;


 
    return answer;
}