#include <iostream>
#include <algorithm>
using namespace std;
int Map[310][310];
int Map2[310][310];
int visited[310][310];
int N,M;
int C;
int dir[4][2] = { {0,-1},{1,0 },{0,1}, {-1,0} };
int dan[500];
int ans;
int cnt; //빙산수
void reset()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Map2[i][j] = 0;
		}
	}


}

void copy()
{
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Map2[i][j] = Map[i][j];
			if (Map[i][j] > 0)
			{
				cnt++;
			}
		}
	}


}





void DFS(int a, int b)
{
	
	visited[a][b] = 1;
	
	cnt--;

	for (int i = 0; i < 4; i++)
	{
		if ((a + dir[i][0] >= 0 && a + dir[i][0] < N) && (b + dir[i][1] >= 0 && b + dir[i][1] < M))
		{
			if (Map2[a + dir[i][0]][b + dir[i][1]] == 0 && Map[a][b]>0)
			{
				Map[a][b]--;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if ((a + dir[i][0] >= 0 && a + dir[i][0] < N) && (b + dir[i][1] >= 0 && b + dir[i][1] < M))
		{
			if (visited[a + dir[i][0]][b + dir[i][1]] == 0 && Map[a + dir[i][0]][b + dir[i][1]] > 0)
			{

				DFS( a + dir[i][0], b + dir[i][1]);
			}
		}
	}
	
	return;
}

void Year()
{
	
	int x = 0; 
	int y=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			
			if (Map[i][j] > 0 && visited[i][j] == 0) {

				x = i; y = j;
				
				break;
			}
			
		}

	}
	DFS(x, y);
	if (cnt != 0)
	{
		ans = 3;
		cout << C-1 ;
		return;
	}
	
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}*/

}

int main()
{

	cin >> N>>M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			
		}
	
	}
	while (1) {
		copy();
		if (ans == 3)
		{
			break;
		}
		
		else if(cnt!=0) {
			C++;
			Year();
			reset();
		}
		else
		{
			break;
		}
	}
	if (ans == 0)
	{
		cout << 0;
	}
		
}

