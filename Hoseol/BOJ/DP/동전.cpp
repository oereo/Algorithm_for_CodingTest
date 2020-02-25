#include <iostream>
#include <algorithm>
using namespace std;
int dp[10005];
int coin[101];
int main()
{
	int n, k,temp;
	cin >> n>>k;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		coin[i - 1] = temp;

	}
	
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 1; j <= k; j++)
		{
			if (j >= coin[i])
			{
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	
	cout<<dp[k]<<endl;
}

