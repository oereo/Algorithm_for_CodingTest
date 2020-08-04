#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct point
{
	int a; int b;
};
int N, K;
int Map[100][100];
int visited[100][100];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ANS = -1;

void MakeRoad(int a, int b, int chance, int length, int before)
{
	for (int i = 0; i < 4; i++)
	{
		int newA = a + dir[i][0]; int newB = b + dir[i][1];
		if (newA >= 0 && newA < N&&newB >= 0 && newB < N&& visited[newA][newB] == 0)
		{
			if (Map[newA][newB] < before)
			{
				visited[newA][newB] = 1;
				MakeRoad(newA, newB, chance, length + 1, Map[newA][newB]);
				visited[newA][newB] = 0;
			}
			else if (Map[newA][newB] - K < before&& chance == 1)
			{
				visited[newA][newB] = 1;
				MakeRoad(newA, newB, 0, length + 1, before - 1);
				visited[newA][newB] = 0;
			}
		}
	}
	ANS = max(ANS, length);

}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ANS = -1;
		memset(Map, 0, sizeof(Map));
		memset(visited, 0, sizeof(visited));
		cin >> N >> K; int HIGH = -1;
		vector<point> Bong;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
				if (Map[i][j] > HIGH)
				{
					Bong.erase(Bong.begin(), Bong.end());
					HIGH = Map[i][j];
					point temp;
					temp.a = i; temp.b = j;
					Bong.push_back(temp);
				}
				else if (Map[i][j] == HIGH)
				{
					point temp;
					temp.a = i; temp.b = j;
					Bong.push_back(temp);
				}
			}
		}
		int len = Bong.size();
		for (int i = 0; i < len; i++)
		{
			point t = Bong[i];

			visited[t.a][t.b] = 1;
			MakeRoad(t.a, t.b, 1, 1, Map[t.a][t.b]);
			visited[t.a][t.b] = 0;
		}
		cout << "#" << test_case << " " << ANS << endl;




	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}