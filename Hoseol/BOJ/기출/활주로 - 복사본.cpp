#include <queue>
#include <vector>
#include <algorithm>
#include<iostream>
#include <cstring>
using namespace std;
int Map[14][21];
int Map_cpy[14][21];
int visited[14];
int D, W, K;
int ANS = -1;
bool check()
{
	for (int i = 0; i < W; i++)
	{
		bool keepGoing = false;
		for (int j = 0; j <= D - K; j++)
		{
			int cnt = 0;
			for (int k = 0; k < K; k++)
			{
				if (Map[j + k][i] == Map[j][i])
				{
					cnt++;
				}
			}
			if (cnt == K) { keepGoing = true;  break; }
		}
		if (!keepGoing)
		{
			return false;
		}
	}
	return true;
}


void DFS(int target, int a, int idx)
{
	if (ANS != -1) { return; }
	if (target == a)
	{
		memcpy(Map_cpy, Map, sizeof(Map));
		for (int i = 0; i < D; i++)
		{
			if (visited[i] >= 1)
			{
				int fill = (visited[i] - 1);
				for (int j = 0; j < W; j++)
				{
					Map[i][j] = fill;
				}
			}
		}
		if (check())
		{
			ANS = target;
		}
		else
		{
			memcpy(Map, Map_cpy, sizeof(Map));
		}
		return;
	}


	for (int i = idx; i < D; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			DFS(target, a + 1, i);
			visited[i] = 2;
			DFS(target, a + 1, i);
			visited[i] = 0;
		}
	}

}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(Map, 0, sizeof(Map));
		memset(visited, 0, sizeof(visited));
		ANS = -1;
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> Map[i][j];
			}
		}
		if (check())
		{
			cout << "#" << test_case << " " << ANS + 1 << endl;
		}
		else
		{
			int putMed = 1;
			while (1)
			{
				if (ANS != -1) { break; }
				for (int i = 0; i < D; i++)
				{
					if (visited[i] == 0)
					{
						visited[i] = 1;
						DFS(putMed, 1, i);
						visited[i] = 2;
						DFS(putMed, 1, i);
						visited[i] = 0;
					}
				}
				putMed++;
			}
			cout << "#" << test_case << " " << ANS << endl;


		}




	}




	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}