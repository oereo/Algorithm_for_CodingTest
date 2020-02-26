#include<iostream>

using namespace std;

unsigned long dp[100] = {0, 1, 1, };
int N = 0;
int main() {
	//dp[1] = 1;
	//dp[2] = 1;
	
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];

	return 0;
}