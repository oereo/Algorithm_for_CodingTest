#include <iostream>
using namespace std;


int dp[1000] = { 1,0,3 };
int main()
{
	int N;
	cin >> N;
	if (N % 2 == 1)
	{
		cout << "0" << endl;
	}
	else {
		for (int i = 4; i <= N; i += 2)
		{
			dp[i] = 3 * dp[i - 2];
			for (int j = 4; j <= i; j += 2)
			{
				dp[i] += 2 * dp[i - j];
			}
		}
		
		cout << dp[N] << endl;
	}

}