#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000000] = { 0 };
int N = 0;
int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	cin >> N;
	
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
			if (i % 3 == 0) {
				dp[i] = min( dp[i/3] + 1, dp[i]);

			}
			else if (i % 2 == 0) {
				dp[i] = min(dp[i/2 ] + 1, dp[i]);
			}
			else {
				dp[i] = min(dp[i - 1] + 1, dp[i]);
			}
		
		
		
	}
		
	cout << dp[N];

	return 0;

}