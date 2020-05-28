#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M[20][20];
int N;
int ANS;
//state: 0:가로 1:세로:2대각선
int k;
int dir[3][2] = { {0,1},{1,0},{1,1} };
void DFS(int a, int b, int before)
{
	if(a==N-1&&b==N-1)
	{
		ANS++; return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (before == 0&&i==1)
		{
			continue;
		}
		else if (before == 1 && i == 0)
		{
			continue;
		}
		if (a + dir[i][0] < N &&b + dir[i][1] < N&&M[a+dir[i][0]][b+dir[i][1]]==0)
		{
			if (i != 2)
			{
				DFS(a + dir[i][0], b + dir[i][1], i);
			}
			else if (M[a + dir[i][0] - 1][b + dir[i][1]] == 0 && M[a + dir[i][0]][b + dir[i][1] - 1] == 0)
			{
				DFS(a + dir[i][0], b + dir[i][1], i);
			}
		}
	}

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> M[i][j];
		}
	}
	M[0][1] = 2;
	DFS(0, 1, 0);
	cout << ANS;
}