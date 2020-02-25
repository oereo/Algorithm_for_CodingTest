#include <iostream>
#include <algorithm>
using namespace std;
int map[101][101];
int visited[101][101];
int cop[101][101];
int n;
int ans = -100;
int x = -10;
void Vclear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}
void c()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cop[i][j] = map[i][j];
		}

	}
}
void cRain(int k)
{
	//cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cop[i][j] <= k)
			{
				cop[i][j] = 0;
			}
			//cout << cop[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
}


void dfs(int i, int j,int c)
{
	visited[i][j] = 1;
	cop[i][j] = c;
	if ((i - 1) >= 0) //위
	{
		if (cop[i - 1][j] != 0 && visited[i - 1][j] == 0)
		{
			cop[i - 1][j] = c;
			dfs(i - 1, j,c);
		}

	}
	if ((i + 1) < n) //아래
	{
		if (cop[i + 1][j] != 0 && visited[i + 1][j] == 0)
		{
			cop[i + 1][j] = c;
			dfs(i + 1, j,c);
		}

	}
	if ((j - 1) >= 0) //왼쪽
	{
		if (cop[i][j - 1] != 0 && visited[i][j - 1] == 0)
		{
			cop[i][j - 1] = c;
			dfs(i, j - 1,c);
		}

	}
	if ((j + 1) < n) //오른쪽
	{
		if (cop[i][j + 1] != 0 && visited[i][j + 1] == 0)
		{
			cop[i][j + 1] = c;
			dfs(i, j + 1,c);
		}

	}
}
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			x = max(x, map[i][j]);

		}
	}
	
	
	for (int i = 1; i <= x; i++)
	{
		c();
		Vclear();
		int cnt = 1;
		cRain(i);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cop[i][j] != 0&&visited[i][j]==0)
				{
					
					dfs(i, j,cnt); cnt++;
				}
				
			}


		}
	
		ans = max(ans, cnt);

	}
	if (ans == 1)
	{
		cout << ans;
	}
	else {
		cout << ans - 1;
	}

}

