/*
<17070 파이프 옮기기 1>
입력
첫째 줄에 집의 크기 N(3 ≤ N ≤ 16)이 주어진다. 
둘째 줄부터 N개의 줄에는 집의 상태가 주어진다. 
빈 칸은 0, 벽은 1로 주어진다.
(1, 1)과 (1, 2)는 항상 빈 칸이다.

출력
첫째 줄에 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수를 출력한다. 
이동시킬 수 없는 경우에는 0을 출력한다. 
방법의 수는 항상 1,000,000보다 작거나 같다.
*/

#include <iostream>
#include <vector>
using namespace std;
int N;
int res = 0;
vector<vector<int>> map;
vector<int> resPos;
//
int beforeX, beforeY;
//
void way(int startx, int starty,int state)//state는 현재 파이프의 상태가 0이면 가로, 1이면 대각선, 2이면 세로 상태
{
	if (startx == N - 1 && starty == N - 1)
	{
		res = res + 1;
		return;
	}
	
	if (state == 0 || state == 2)//지금이 가로 or 대각이면 가로확인
	{
		if (starty + 1 < N && map[startx][starty + 1] == 0)//가로가 갈수있으면
		{
			way(startx, starty+1,0);
		}	
	}
	
	if (state == 1 || state == 2)//지금이 세로 or 대각이면 세로확인
	{
		if (startx + 1 < N && map[startx + 1][starty] == 0)//세로가 갈수있으면
		{
			way(startx+1, starty,1);
		}
	}	
	
	//모든 경우 가능한 대각확인, 대각으로 갈 수있다면!
	if (startx + 1 < N && starty + 1 < N && map[startx][starty + 1] == 0 && map[startx + 1][starty] == 0 && map[startx + 1][starty + 1] == 0)
	{
		way(startx + 1, starty + 1,2);
	}
}

int main()
{
	cin >> N;
	map.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	way(0, 1,0);//0,0에 막대가 가로로 누운 상태로 시작하여 이동하는 DFS

	cout << res << endl;
}

/*
#include <iostream>
#include <vector>
using namespace std;
int N;
int res = 0;
vector<vector<int>> map;

int state = 0;//현재 파이프의 상태가 0이면 가로, 1이면 대각선, 2이면 세로 상태
void way(int startx, int starty)
{
	if (startx == N - 1 && starty == N - 1)
	{
		res = res + 1;
		return;
	}

	if (state != 1)//지금이 가로 or 대각이면 가로확인
	{
		if (starty + 1 < N && map[startx][starty + 1] == 0)//가로가 갈수있으면
		{
			state = 0;
			way(startx, starty + 1);
		}
	}

	if (state != 0)//지금이 세로 or 대각이면 세로확인
	{
		if (startx + 1 < N && map[startx + 1][starty] == 0)//세로가 갈수있으면
		{
			state = 1;
			way(startx + 1, starty);
		}

	}

	//모든 경우 가능한 대각확인, 대각으로 갈 수있다면!
	if (startx + 1 < N && starty + 1 < N && map[startx][starty + 1] == 0 && map[startx + 1][starty] == 0 && map[startx + 1][starty + 1] == 0)
	{
		state = 2;
		way(startx + 1, starty + 1);
	}
}

int main()
{
	cin >> N;
	map.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	way(0, 1);//0,0에 막대가 가로로 누운 상태로 시작하여 이동하는 DFS

	cout << res << endl;
}*/