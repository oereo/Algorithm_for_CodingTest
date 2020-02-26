#include<iostream>

using namespace std;

int dp[1000] = { 0,1,2 };
int N = 0;
int main() {

	cin >> N;

	for (int i = 3; i <= N; i++) {

		dp[i] = dp[i - 1] + dp[i - 2];

	}
	cout << dp[N];
	
	

}