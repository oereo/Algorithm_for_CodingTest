#include<iostream>

using namespace std;

int dp[13] = { 0,1,2,4 };

int main() {
	int count = 0;
	cin >> count;
	for (int i = 1; i <= count; i++) {
		int N = 0;
		cin >> N;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << endl;
	}


	return 0;
}