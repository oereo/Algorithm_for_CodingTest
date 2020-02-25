#include <iostream>
using namespace std;



long long  dp[1000][10];
long long ans;
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}


	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][1];
			}
			else if (j == 9)
			{

				dp[i][9] = dp[i - 1][8];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
		}
		
		
	}

		for (int i = 0; i <= 9; i++)
		{
			ans += dp[N][i];
		}
		ans %= 1000000000;
		cout << ans;

}

