#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char map[2001][2001];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char cmp = map[i][j];
			int count4 = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dir[k][0] >= 0 && i + dir[k][0] < N&&j + dir[k][1] >= 0 && j + dir[k][1] < M)
				{
					if (cmp == map[i + dir[k][0]][j + dir[k][1]])
					{
						count4++;
					}
				}
				else { count4++; }
			}
			if (count4 == 4)
			{
				cnt++;
			}

		}
	}
	long long ans = 1;
	for(int i=0;i<cnt;i++)
	{
		ans *= 2;
		ans %= 1000000007;
	}
	cout << ans;
}

