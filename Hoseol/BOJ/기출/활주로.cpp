
/*4 4 3 3 3 3 2 2 2 
4 4 3 3 1 1 2 2 3 
3 3 2 2 1 1 1 1 2 
1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 
2 2 1 1 1 1 1 1 1 
2 2 1 1 1 1 1 1 1 
2 2 2 2 2 2 1 1 1 
3 3 3 3 2 2 2 2 1 */
//9 4
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, X;
int Map[100][100];

bool aw(int a)
{   
	int visited[100];
	memset(visited, 0, sizeof(visited));
	bool build = false;
	for (int b = 0; b < N; b++)
	{
		if (b + 1 == N) { break; }
		if (b + 1 < N&& Map[a][b] - Map[a][b + 1] == 0)
		{
			continue;
		}
		else if (b + 1 < N&& Map[a][b] - Map[a][b + 1] == 1)
		{
			if (b + X < N)
			{
				for (int ground = 1; ground <= X; ground++)
				{
					if (Map[a][b + 1] == Map[a][b + ground]&&visited[b+ground]==0)
					{
						visited[b + ground] = 1;
						continue;
					}
					else
					{
						return false;
					}
				}
				build = true;
			}
			else
			{
				return false;
			}
		}
		else if (b + 1 < N&& Map[a][b] - Map[a][b + 1] == -1)
		{
			if (b - X+1 >= 0)
			{
				for (int ground = 0; ground < X; ground++)
				{
					if (Map[a][b] == Map[a][b -ground]&&visited[b-ground]==0)
					{
						visited[b - ground] = 1;
						continue;
					}
					else
					{
						return false;
					}
				}
				build = true;
			}
			else
			{
				return false;
			}
		
		}
		else
		{
			return false;
		}
	}
	cout << "행:" << a << endl;
	return true;
}

bool aw2(int a)
{
	int visited[100];
	memset(visited, 0, sizeof(visited));
	bool build = false;
	for (int b = 0; b < N; b++)
	{
		if (b + 1 == N) { break; }
		if (b + 1 < N&& abs(Map[b][a] - Map[b+1][a]) == 0)
		{
			continue;
		}
		else if (b + 1 < N&& Map[b][a] - Map[b+1][a] == 1)
		{

			if (b + X < N)
			{
				for (int ground = 1; ground <= X; ground++)
				{
					if (Map[b+1][a] == Map[b+ground][a]&&visited[b+ground]==0)
					{
						visited[b + ground] = 1;
						continue;
					}
					else
					{
						return false;
					}
				}
				build = true;
			}
			else
			{
				return false;
			}
		}
		else if (b + 1 < N&& Map[b][a] - Map[b+1][a] == -1)
		{
			if (b - X >= -1)
			{
				for (int ground = 0; ground < X; ground++)
				{
					if (Map[b][a] == Map[b-ground][a]&&visited[b-ground]==0)
					{
						visited[b - ground] = 1;
						continue;
					}
					else
					{
						return false;
					}
				}
				build = true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	cout << "열:" << a << endl;
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;
		memset(Map, 0, sizeof(Map));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (aw(i))
			{
				cnt++;
			}
			if (aw2(i))
			{
				cnt++;
			}

		}
		cout <<"#"<<test_case<<" "<<cnt<<endl;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}