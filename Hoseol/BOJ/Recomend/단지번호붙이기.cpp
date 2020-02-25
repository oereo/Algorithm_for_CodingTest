#include <iostream>
#include <algorithm>
using namespace std;
int Map[100][100];
int visited[100][100];
int N;
int C;
int dir[4][2] = { {0,-1},{1,0 },{0,1}, {-1,0} };
int dan[500];

void DFS(int n,int a, int b)
{
		Map[a][b] = C;
		dan[C - 1]++;
		visited[a][b] = 1;
	

	for (int i = 0; i < 4; i++)
	{
		if ((a + dir[i][0] >= 0 && a + dir[i][0] < N) && (b + dir[i][1] >= 0 && b + dir[i][1] < N))
		{
			if (visited[a + dir[i][0]][b + dir[i][1]]==0&& Map[a + dir[i][0]][b + dir[i][1]]==1)
			{

				DFS(n, a + dir[i][0], b + dir[i][1]);
			}
		}

	}
	return;

}

int main()
{
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 1 && visited[i][j] == 0) {
				C++;
				DFS(C, i, j);
			}
		}
	}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << C<<endl;
	sort(dan, dan + 500);
	for (int i = 0; i < 500; i++)
	{
		if (dan[i] != 0)
		{
			cout << dan[i] << endl;
		}
	}





}

