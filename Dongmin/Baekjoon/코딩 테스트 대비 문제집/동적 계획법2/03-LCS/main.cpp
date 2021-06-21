#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[1001][1001];

int solve(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    dp[0][0] = (s1[0] == s2[0]);
    for (int i=1; i<len1; i++) {
        dp[i][0] = max((int) (s1[i] == s2[0]), dp[i-1][0]);
    }
    for (int i=1; i<len2; i++) {
        dp[0][i] = max((int) (s1[0] == s2[i]), dp[0][i-1]);
    }

    for (int i=1; i<len1; i++) {
        for (int j=1; j<len2; j++) {
            dp[i][j] = (s1[i] == s2[j] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]));
        }
    }

    return dp[len1-1][len2-1];
}

int main() {
    memset(dp, 0, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << endl;
    return 0;
}