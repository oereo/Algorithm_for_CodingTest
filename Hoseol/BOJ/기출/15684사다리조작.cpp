#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sadari[100][100];
int H;
int N, M;
bool check = true;
int ANSWER = -1;



void DFS(int ans, int a, int b)
{
	if (a == H&& ans== b)
	{
		return;
	}
	else if (a==H&& ans != b)
	{
		check = false;
		return;
	}
	if (sadari[a][b] == 1)
	{
		DFS(ans, a+1, b + 1);
	}
	else if (sadari[a][b] == -1)
	{
		DFS(ans, a + 1, b - 1);
	}
	else
	{
		int go = 1;
		while (1)
		{
			if (a + go == H) { break; }
			if (sadari[a+go][b]!=0)
			{
				break;
			}
			if (sadari[a + go][b] == 0)
			{
				go++;
			}
		}
		DFS(ans, a + go, b);
	}
}


void set(int ans,int cnt)
{
	if(cnt==ans)
	{ 
		for (int i = 0; i < N; i++)
		{
			DFS(i, 0, i);
			if (check == false)
			{
				check = true;
				return;
			}
	    }
		if (check == true)
		{
			ANSWER = ans;
			return;
		}
	}
	else
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (sadari[i][j] == 0 && sadari[i][j + 1] == 0)
				{
					sadari[i][j] = 1; sadari[i][j + 1] = -1;
					set(ans, cnt + 1);
					sadari[i][j] = 0; sadari[i][j + 1] = 0;
				}
			}
		}
	}
}

void first()
{
	for (int i = 0; i < N; i++)
	{
		DFS(i, 0, i);
		if (check == false)
		{
			check = true;
			return;
		}
	}
	if (check == true)
	{
		ANSWER = 0;
		return;
	}
}


int main()
{
	
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		a--; b--;
		sadari[a][b] = 1;
		sadari[a][b + 1] = -1;
	}
	int ans = 0;
	first();


	if (ANSWER == -1) 
	{
		while (1)
		{
			ans++;
			if (ans > 3) { break; }
			for (int i = 0; i < H; i++)
			{
				for (int j = 0; j < N - 1; j++)
				{
					if (sadari[i][j] == 0 && sadari[i][j + 1] == 0)
					{
						sadari[i][j] = 1; sadari[i][j + 1] = -1;
						set(ans, 1);
						if (ANSWER != -1) { break; }
						sadari[i][j] = 0; sadari[i][j + 1] = 0;
					}
				}
				if (ANSWER != -1) { break; }
			}
			if (ANSWER != -1) { break; }
		}
	}
	cout << ANSWER;
}
