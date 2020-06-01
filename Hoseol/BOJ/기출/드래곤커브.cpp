#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int map[200][200];
int main()
{
	int N;
	int x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> dp[21];
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		map[y + dir[d][0]][x + dir[d][1]] = 1;
		dp[0].push_back(d);
		y = y + dir[d][0]; x = x + dir[d][1];
		for (int j = 1; j <= g; j++)
		{
			dp[j] = dp[j - 1];
			for (int k = 0; k < dp[j - 1].size(); k++)
			{

				dp[j].push_back(dp[j - 1][dp[j - 1].size() - 1 - k] + 1);
				int siz = dp[j].size() - 1;
				if (dp[j][siz] == 4) { dp[j][siz] = 0; }
				map[y + dir[dp[j][siz]][0]][x + dir[dp[j][siz]][1]] = 1;
				y = y + dir[dp[j][siz]][0]; x = x + dir[dp[j][siz]][1];
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
			{
				answer++;
			}

		}
	}
	cout << answer << endl;

}