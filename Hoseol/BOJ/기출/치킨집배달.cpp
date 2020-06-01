#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int N, M; //M은 살려놓을 치킨집 개수
int Map[51][51];
int destr = 0;
int ChickDist = 1000000;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

struct point {
	int a; int b; int dist = 0;
};
int DIST_FIND(int a, int b)
{
	int dist=1000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 2)
			{
				dist = min(dist, abs(i - a) + abs(j - b));
			}
		}
	}
	return dist;
}

void DESTROY(int num , int tar,int key)
{
	if (num == tar)
	{
		int temp_dist = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Map[i][j] == 1)
				{
					temp_dist += DIST_FIND(i, j);
				}
			}
		}
		ChickDist = min(ChickDist, temp_dist);
		return;
	}
	if (num > tar) { return; }
	
	for (int i = key; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 2)
			{
				Map[i][j] = 0;
				DESTROY(num + 1, tar,i);
				Map[i][j] = 2;
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2) { destr++; }
		}
	}
	destr = destr - M; //부술 치킨집수
	DESTROY(0, destr,0);
	cout << ChickDist;
}