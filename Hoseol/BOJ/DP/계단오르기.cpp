#include <iostream>
#include <algorithm>
using namespace std;
struct stair {
	int a=0;
	int b=0;


};
stair dp[1000];
int S[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}

	dp[1].a = S[0];
	dp[2].a = S[0]+S[1];
	dp[2].b = S[1];

	for (int i = 3; i <= n; i++)
	{
		dp[i].a = dp[i - 1].b + S[i - 1];
		dp[i].b = max(dp[i - 2].a, dp[i - 2].b) + S[i - 1];


	}

	cout << max(dp[n].a, dp[n].b);

}

