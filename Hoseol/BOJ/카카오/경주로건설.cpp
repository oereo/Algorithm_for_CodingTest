#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<vector<int>> Map;
int cost[26][26];
int N;

bool turn(int before, int now)
{
	if (before == 0 && (now == 1 || now == 3)) { return true; }
	if (before == 1 && (now == 0 || now == 2)) { return true; }
	if (before == 2 && (now == 1 || now == 3)) { return true; }
	if (before == 3 && (now == 0 || now == 2)) { return true; }
	return false;
}
void DFS(int a, int b, int before, int money)
{
	if (a == N - 1 && b == N - 1)
	{
		if (cost[a][b] == 0 || money <= cost[N - 1][N - 1])
		{
			cost[N - 1][N - 1] = money;
			//  cout<<N-1<<" , "<<N-1<<" ->"<<cost[N-1][N-1]<<endl;
		}
		return;
	}

	if (cost[a][b] == 0 || money <= cost[a][b])
	{
		cost[a][b] = money;
		// cout<<a<<" , "<<b<<" ->"<<cost[a][b]<<endl;
		for (int i = 0; i < 4; i++)
		{
			int newA = a + dir[i][0]; int newB = b + dir[i][1];
			if (newA >= 0 && newA < N&&newB >= 0 && newB < N&&Map[newA][newB] == 0)
			{
				if (turn(before, i))
				{
					DFS(newA, newB, i, money + 600);
				}
				else
				{
					DFS(newA, newB, i, money + 100);
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	Map = board;
	N = board.size();
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		int newA = dir[i][0]; int newB = dir[i][1];
		if (newA >= 0 && newA < N&&newB >= 0 && newB < N&&Map[newA][newB] == 0)
		{
			DFS(newA, newB, i, 100);
		}
	}



	return cost[N - 1][N - 1];
}