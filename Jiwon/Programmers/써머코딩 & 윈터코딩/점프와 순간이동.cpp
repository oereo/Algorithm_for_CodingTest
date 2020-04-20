#include <iostream>
using namespace std;

long long dp[1000000001];

int solution(int n){
    int ans = 0;
	
    dp[1] = {1};
    dp[2] = {2};
    
    for(int i = 3; i <= n; i++){
        if((i%2) == 0){
            dp[i] = dp[i/2];
        }
        else{
            dp[i] = dp[i - 1] + 1;
        }
    }
    
    ans = dp[n];
    
    return ans;
}