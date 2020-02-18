#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int answer = -1;
vector<int> dp[100];


int solution(int N, int number) {
    dp[1].push_back(N);
	for (int i = 2; i <= 8; i++)
	{
		if (answer == -1)
		{
			int pass_num = N;
			for (int n = 1; n < i; n++)
			{
				pass_num = (pass_num * 10) + N;
			}
			dp[i].push_back(pass_num);

			for (int cnt = 1; cnt < i; cnt++)
			{
				int num;
				int len1 = dp[cnt].size();
				int len2 = dp[i - cnt].size();
				for (int j = 0; j < len1; j++)
				{
					for (int k = 0; k < len2; k++)
					{
						num = dp[cnt][j] + dp[i - cnt][k];
						dp[i].push_back(num);
						num = dp[cnt][j] - dp[i - cnt][k];
						dp[i].push_back(num);
						num = dp[cnt][j] * dp[i - cnt][k];
						dp[i].push_back(num);
						if (dp[i - cnt][k] != 0) {
							num = dp[cnt][j] / dp[i - cnt][k];
							dp[i].push_back(num);
							
						}

					}


				}
			}
				sort(dp[i].begin(), dp[i].end());
				dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());
				int len3 = dp[i].size();
				
				for (int h = 0; h < len3; h++)
				{
					
					if (number == abs(dp[i][h]))
					{
						answer = i;
						
						
						break;
					}
				}
		}

	}



	
    return answer;
}