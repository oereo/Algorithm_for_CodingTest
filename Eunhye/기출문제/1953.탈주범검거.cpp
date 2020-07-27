#include <iostream>
#include <vector>
using namespace std;

int T, N, M, R, C, L,result;
vector<vector<int>> map;
vector<vector<int>> visited;
int dx[4] = { -1,1,0,0 };//»óÇÏÁÂ¿ì ¼ø
int dy[4] = { 0,0,-1,1 };

void DFS(int row, int col, int time);

void up(int row,int col, int time)
{
	if (row + dx[0] >= 0 && row + dx[0] < N&&col + dy[0] >= 0 && col + dy[0] < M&&visited[row + dx[0]][col + dy[0]] == 0)
	{
		if (map[row + dx[0]][col + dy[0]] == 1 || map[row + dx[0]][col + dy[0]] == 2 || map[row + dx[0]][col + dy[0]] == 5 || map[row + dx[0]][col + dy[0]] == 6)
		{
			visited[row + dx[0]][col + dy[0]] = 1;
			result++;
			DFS(row + dx[0], col + dy[0], time - 1);
		}
	}
}

void down(int row, int col, int time)
{
	if (row + dx[1] >= 0 && row + dx[1] < N &&col + dy[1] >= 0 && col + dy[1] < M &&visited[row + dx[1]][col + dy[1]] == 0)
	{
		if (map[row + dx[1]][col + dy[1]] == 1 || map[row + dx[1]][col + dy[1]] == 2 || map[row + dx[1]][col + dy[1]] == 4 || map[row + dx[1]][col + dy[1]] == 7)
		{
			visited[row + dx[1]][col + dy[1]] = 1;
			result++;
			DFS(row + dx[1], col + dy[1], time - 1);
		}
	}
}

void left(int row, int col, int time)
{
	if (row + dx[2] >= 0 && row + dx[2] < N&&col + dy[2] >= 0 && col + dy[2] < M&&visited[row + dx[2]][col + dy[2]] == 0)
	{
		if (map[row + dx[2]][col + dy[2]] == 1 || map[row + dx[2]][col + dy[2]] == 3 || map[row + dx[2]][col + dy[2]] == 4 || map[row + dx[2]][col + dy[2]] == 5)
		{
			visited[row + dx[2]][col + dy[2]] = 1;
			result++;
			DFS(row + dx[2], col + dy[2], time - 1);
		}
	}
}

void right(int row, int col, int time)
{
	if (row + dx[3] >= 0 && row + dx[3] < N&&col + dy[3] >= 0 && col + dy[3] < M&&visited[row + dx[3]][col + dy[3]] == 0)
	{
		if (map[row + dx[3]][col + dy[3]] == 1 || map[row + dx[3]][col + dy[3]] == 3 || map[row + dx[3]][col + dy[3]] == 6 || map[row + dx[3]][col + dy[3]] == 7)
		{
			visited[row + dx[3]][col + dy[3]] = 1;
			result++;
			DFS(row + dx[3], col + dy[3], time - 1);
		}
	}
}
void DFS(int row, int col, int time)
{
	if (time == 0)
		return;
	
	switch (map[row][col])
	{		
		case 1://»óÇÏÁÂ¿ì
			up(row, col, time);
			down(row, col, time);
			left(row, col, time);
			right(row, col, time);
			break;
		case 2://»óÇÏ
			up(row, col, time);
			down(row, col, time);
			break;
		case 3://ÁÂ¿ì
			left(row, col, time);
			right(row, col, time);
			break;
		case 4://»ó¿ì
			up(row, col, time);
			right(row, col, time);
			break;
		case 5://ÇÏ¿ì
			down(row, col, time);
			right(row, col, time);
			break;
		case 6://ÇÏÁÂ
			down(row, col, time);
			left(row, col, time);
			break;
		case 7://»óÁÂ
			up(row, col, time);
			left(row, col, time);
			break;
	}
	
}


int main()
{
	cin >> T;
	int t = 1;
	
	while (t <= T)
	{
		cin >> N >> M >> R >> C >> L;

		map.resize(N, vector<int>(M, 0));
		visited.resize(N, vector<int>(M, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
				visited[i][j] = 0;
			}
		}
		visited[R][C] = 1;
		L--;
		result = 1;
		if (L != 1)
			DFS(R, C,L);

		cout << "#" << t << " " << result << endl;
		map.clear();
		visited.clear();
		t++;
	}
}