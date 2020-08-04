#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
struct point {
	int a; int b;
};
int dir[5][2] = { {0,0},{-1,0},{0,1},{1,0},{0,-1} };
int Ans;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int M, A; Ans = 0;
		vector<int> Map[11][11];
		deque<int> movP[2];
		map<int, int> charge;
		deque<point> BFS;
		cin >> M >> A;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int t;
				cin >> t;
				movP[i].push_back(t);
			}
		}
		for (int i = 0; i < A; i++)
		{
			int a; int b; int dist; int c;
			cin >> b >> a >> dist >> c;
			b--; a--;
			charge[i] = c;
			for (int j = a - dist; j <= a + dist; j++)
			{
				for (int k = b - dist; k <= b + dist; k++)
				{
					if ((abs(a - j) + abs(b - k)) <= dist)
					{
						if (j >= 0 && j < 10 && k >= 0 && k < 10)
						{
							Map[j][k].push_back(i);
						}
					}

				}

			}
		}



		point p1; p1.a = 0; p1.b = 0;
		point p2; p2.a = 9; p2.b = 9;
		BFS.push_back(p1); BFS.push_back(p2);
		while (!BFS.empty() || !movP[0].empty())
		{
			point p1 = BFS[0];
			point p2 = BFS[1];
			BFS.pop_front();
			BFS.pop_front();
			int len1 = Map[p1.a][p1.b].size();
			int len2 = Map[p2.a][p2.b].size();
			int t = 0; int plus = 0;
			if (len1 > 0 && len2 > 0)
			{
				for (int i = 0; i < len1; i++)
				{
					for (int j = 0; j < len2; j++)
					{
						if (Map[p1.a][p1.b][i] == Map[p2.a][p2.b][j])
						{
							t = charge[Map[p1.a][p1.b][i]];
							plus = max(plus, t);
						}
						else
						{
							t = charge[Map[p1.a][p1.b][i]] + charge[Map[p2.a][p2.b][j]];
							plus = max(plus, t);
						}
					}

				}
				Ans += plus;
			}
			else
			{
				int plus = 0;
				for (int i = 0; i < len1; i++)
				{
					plus = max(plus, charge[Map[p1.a][p1.b][i]]);
				}
				for (int i = 0; i < len2; i++)
				{
					plus = max(plus, charge[Map[p2.a][p2.b][i]]);
				}
				Ans += plus;
			}



			if (movP[0].size() > 0)
			{
				int newA = p1.a + dir[movP[0].front()][0];
				int newB = p1.b + dir[movP[0].front()][1];
				movP[0].pop_front();
				point newP; newP.a = newA; newP.b = newB;
				BFS.push_back(newP);

				int newA2 = p2.a + dir[movP[1].front()][0];
				int newB2 = p2.b + dir[movP[1].front()][1];
				movP[1].pop_front();
				point newP2; newP2.a = newA2; newP2.b = newB2;
				BFS.push_back(newP2);
			}
		}
		cout << "#" << test_case << " " << Ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}