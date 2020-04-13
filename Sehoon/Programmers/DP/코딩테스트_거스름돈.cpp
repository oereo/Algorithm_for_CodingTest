#include <string>
#include <vector>

using namespace std;
//struct cnt{
//    int one = 0;
//    int two = 0;
//    int five = 0;
//};

int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    int length = money.size();
    dp[0] = 1;
    //dp[1] = 1;
    for(int i = 0; i<length; i++){
        for(int j = 1; j<=n; j++){
            if(j>=money[i]){
                dp[j]+=dp[j-money[i]];
                dp[j] = dp[j]%1000000007;
            }
        }
    }
    
    answer = dp[n]%1000000007;
    
    
    return answer;
}