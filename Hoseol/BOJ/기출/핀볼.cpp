#include <vector>
#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int Map[100][100];
int Ans = -1;
unordered_map<int, int> warmHall;
struct Ball {

	int a;
	int b;
	int dirA;
	int dirB;
};
Ball Player;
int N;


bool Hit(int a, int b, int cmp)
{
	if (cmp == 1)
	{
		if (a == 1 && b == 0)
		{
			Player.dirA = 0; Player.dirB = 1;
			return true;
		}
		else if (a == 0 && b == -1)
		{
			Player.dirA = -1; Player.dirB = 0;
			return true;
		}
		else
		{
			Player.dirA *= -1; Player.dirB *= -1;
			return false;
		}
	}
	else if (cmp == 2)
	{
		if (a == -1 && b == 0)
		{
			Player.dirA = 0; Player.dirB = 1;
			return true;
		}
		else if (a == 0 && b == -1)
		{
			Player.dirA = 1; Player.dirB = 0;
			return true;
		}
		else
		{
			Player.dirA *= -1; Player.dirB *= -1;
			return false;
		}
	}
	else if (cmp == 3)
	{
		if (a == -1 && b == 0)
		{
			Player.dirA = 0; Player.dirB = -1;
			return true;
		}
		else if (a == 0 && b == 1)
		{
			Player.dirA = 1; Player.dirB = 0;
			return true;
		}
		else
		{
			Player.dirA *= -1; Player.dirB *= -1;
			return false;
		}
	}
	else if (cmp == 4)
	{
		if (a == 1 && b == 0)
		{
			Player.dirA = 0; Player.dirB = -1;
			return true;
		}
		else if (a == 0 && b == 1)
		{
			Player.dirA = -1; Player.dirB = 0;
			return true;
		}
		else
		{
			Player.dirA *= -1; Player.dirB *= -1;
			return false;
		}
	}
	else if (cmp == 5)
	{
		Player.dirA *= -1; Player.dirB *= -1;
		return false;
	}

}

void Warp(int tarA, int tarB)
{
	int warp = warmHall[-Map[tarA][tarB]];
	int newA = warp / N;
	int newB = warp % N;
	Player.a = newA; Player.b = newB;

}


int Go(int destA, int destB)
{
	int score = 0;
	while (1)
	{
		Player.a = Player.a + Player.dirA;
		Player.b = Player.b + Player.dirB;
		if (!(Player.a >= 0 && Player.a < N&&Player.b >= 0 && Player.b < N))
		{
			score *= 2;
			score++;
			return score;
		}
		else if ((Player.a == destA && Player.b == destB) || Map[Player.a][Player.b] == -1)
		{
			return score;
		}
		else if (Map[Player.a][Player.b] >= 1 && Map[Player.a][Player.b] <= 5)
		{
			if (!Hit(Player.dirA, Player.dirB, Map[Player.a][Player.b]))
			{
				score *= 2;
				score++;
				return score;
			}
			score++;

		}
		else if (abs(Map[Player.a][Player.b]) >= 6 && abs(Map[Player.a][Player.b]) <= 10)
		{
			Warp(Player.a, Player.b);
		}

	}
	return score;

}



int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
				if (Map[i][j] >= 6 && Map[i][j] <= 10)
				{
					if (warmHall[Map[i][j]] == 0)
					{
						warmHall[Map[i][j]] = i * N + j;
					}
					else
					{
						Map[i][j] *= -1;
						warmHall[Map[i][j]] = i * N + j;
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Map[i][j] == 0)
				{
					for (int k = 0; k < 4; k++)
					{
						Player.a = i;
						Player.b = j;
						Player.dirA = dir[k][0];
						Player.dirB = dir[k][1];
						Ans = max(Ans, Go(i, j));
					}
				}
			}
		}

		cout << "#" << test_case << " " << Ans << "\n";
		memset(Map, 0, sizeof(Map));
		warmHall.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}