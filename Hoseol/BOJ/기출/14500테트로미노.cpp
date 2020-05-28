#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int  dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int Map[501][501];
int visited[501][501];
int N, M;
int MAX = -1;
vector<vector<int>> str;


void DFS(int a, int b, int cnt, int tmp)
{

	if (cnt == 3)
	{
		int cal = tmp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int newA = str[i][0] + dir[j][0]; int newB = str[i][1] + dir[j][1];
				if (newA >= 0 && newA < N&&newB >= 0 && newB < M &&visited[newA][newB] == 0)
				{
					tmp = max(tmp, cal + Map[newA][newB]);
				}
			}

		}
		MAX = max(MAX, tmp);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int newA = a + dir[i][0]; int newB = b + dir[i][1];
		if (newA >= 0 && newA < N&&newB >= 0 && newB < M &&visited[newA][newB] == 0)
		{
			visited[newA][newB] = 1;
			vector<int> t; t.push_back(newA); t.push_back(newB);
			str.push_back(t);
			DFS(newA, newB, cnt + 1, tmp + Map[newA][newB]);
			str.pop_back();
			visited[newA][newB] = 0;
		}
	}


}



int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 1;
			vector<int> t; t.push_back(i); t.push_back(j);
			str.push_back(t);
			DFS(i, j, 1, Map[i][j]);
			str.pop_back();
			visited[i][j] = 0;
		}
	}

	cout << MAX;
}






