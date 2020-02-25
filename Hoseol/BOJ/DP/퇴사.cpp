#include <iostream>
#include <algorithm>
using namespace std;
struct qq {

	int T=0;
	int N = 0;
	int ma = 0;
};
qq dp[1000];
int a; int b;
int ans;
int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> a >> b;
		dp[i].T = a;
		dp[i].N = b;
	}
	for (int i = 2; i <= k+1; i++)
	{		
		for (int j = 1; j < i; j++)
		{
			dp[i].ma = max(dp[i].ma, dp[j].ma);
			if (i - j == dp[j].T)
			{
				dp[i].ma = max(dp[i].ma, dp[j].ma+dp[j].N);
				
			}
		}
		
		ans = max(ans, dp[i].ma);
		
	}

	cout << ans << endl;
}