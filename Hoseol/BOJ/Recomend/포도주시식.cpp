#include <iostream>
#include <algorithm>
using namespace std;

struct wine {
	int a = 0;
	int b = 0;
	int c = 0;

};
wine dp[10001];
int W[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> W[i];
	}
	dp[1].a = W[0];
	dp[2].a = W[1] + W[0];
	dp[2].b = W[1];

	dp[3].a = max(dp[2].b, dp[2].c) + W[2];
	dp[3].b = max(dp[1].c, max(dp[1].a, dp[1].b))+W[2];
	dp[3].c = W[2];

	for (int i = 4; i <= n; i++)
	{
		dp[i].a = max(dp[i - 1].b,dp[i-1].c) + W[i - 1];
		dp[i].b = max(dp[i-2].c,max(dp[i - 2].a, dp[i - 2].b))+W[i-1];
		dp[i].c = max(dp[i - 3].c, max(dp[i - 3].a, dp[i - 3].b)) + W[i - 1];


	}
	int Max = -10000;
	for (int i = 0; i <= n; i++)
	{
		Max = max(Max,max(dp[i].c, max(dp[i].a, dp[i].b)));

	}

	cout << Max;


}

