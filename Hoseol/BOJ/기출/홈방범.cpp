#include <vector>
#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int Map[100][100];
int N; int M; int ANS;


int howMany(int a, int b, int range)
{
	int cnt = 0;
	for (int i = a - range; i <= a + range; i++)
	{
		for (int j = b - range; j <= b + range; j++)
		{
			if (i >= 0 && i < N&&j >= 0 && j < N)
			{
				if (abs(i - a) + abs(j - b) <= range && Map[i][j] == 1)
				{
					cnt++;
				}
			}
		}
	}
	return cnt;
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0; ANS = 0;
		memset(Map, 0, sizeof(Map));
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
			}

		}
		int range = 0;

		while (range <= N)
		{
			range++;
			int MAX = -1;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					MAX = max(MAX, howMany(i, j, range - 1));
				}
			}
			int money = (MAX*M) - ((range*range) + (range - 1)*(range - 1));
			if (money >= 0)
			{
				ANS = max(ANS, MAX);
			}
		}
		cout << "#" << test_case << " " << ANS << endl;

	}
	return 0;
}