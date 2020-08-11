#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N, M,r,c,d;
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
map<int, int> Rot;
map<int, int>Back;
//북:0 동:1 남:2 서:3
int visited[50][50];
int Map[50][50];
int ANS;
void set()
{
	Rot[0] = 3; Back[0] = 3;
	Rot[1] = 0; Back[1] = 0;
	Rot[2] = 1; Back[2] = 1;
	Rot[3] = 2; Back[3] = 2;
}


void DFS(int a, int b, int d,int cnt,int back)
{
	if (visited[a][b] == 0 &&back==0)
	{
		visited[a][b] = 1;
		Map[a][b] = 2;
		ANS++;
	}
	int newA = a + dir[d][0]; int newB = b + dir[d][1];
	if (newA>=0&&newA<N&&newB>=0&&newB<M&&Map[newA][newB]==0&&visited[newA][newB] == 0)
	{
		DFS(newA, newB, Rot[d],0,0);
	}
	else if(newA >= 0 && newA < N&&newB >= 0 && newB < M&&(Map[newA][newB] == 1 || visited[newA][newB] == 1))
	{
		if (cnt == 4)
		{
			int newA2 = a + dir[Back[d]][0]; int newB2 = b + dir[Back[d]][1];
			if (Map[newA2][newB2] == 1)
			{
				return;
			}
			else if (newA2 >= 0 && newA2 < N&&newB2 >= 0 && newB2 < M)
			{
				DFS(newA2, newB2, d, 0,1);
			}
		}
		else 
		{
			DFS(a, b, Rot[d], cnt + 1,0);
		}
	}

}

int main()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	set();
	DFS(r, c, d,0,0);
	cout << ANS;


}