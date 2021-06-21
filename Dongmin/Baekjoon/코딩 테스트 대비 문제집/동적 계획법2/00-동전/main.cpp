#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[21][10001];

int solve(int n, int target, vector<int> coins) {
    if (n==1) return (target % coins[0] == 0);

    int &ret = dp[n][target];
    if (ret != -1) return ret;

    int biggest = coins.back();
    int remainder = target;
    coins.pop_back();

    int sum = 0;
    while (remainder >= 0) {
        sum += solve(n-1, remainder, coins);
        remainder -= biggest;
    }

    ret = sum;
    return ret;
}

int main() {
    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int N, M;
        cin >>N;
        vector<int> coins(N, 0);
        memset(dp, -1, sizeof(dp));

        for (int i=0; i<N; i++) {
            cin >> coins[i];
        }
        cin >> M;
        cout << solve(N, M, coins) << endl;
    }
    
    return 0;
}