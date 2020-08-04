#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
map<int, int> rev;
int MAP[100][100];
void Hash()
{
	rev[0] = 1;
	rev[1] = 0;
	rev[2] = 3;
	rev[3] = 2;
}
struct virus {
	int a, b;
	int num;
	int move;
};
int Map[100][100];
int visited[100][100];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	Hash();
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		deque<virus> BFS;
		int N, M, K;
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			virus t;
			cin >> t.a >> t.b >> t.num >> t.move;
			t.move--;
			BFS.push_back(t);
		}
		int Time = 0;

		while (Time < M)
		{
			int len = BFS.size();
			deque<virus> temp;
			memset(Map, 0, sizeof(Map));
			memset(visited, 0, sizeof(visited));
			for (int i = 0; i < len; i++)
			{
				virus now = BFS.front();
				BFS.pop_front();
				int newA = now.a + dir[now.move][0]; int newB = now.b + dir[now.move][1];
				if (newA == 0 || newA == N - 1 || newB == 0 || newB == N - 1)
				{
					virus New;
					New.a = newA; New.b = newB; New.move = rev[now.move]; New.num = (now.num / 2);
					BFS.push_back(New);
				}
				else
				{
					virus New;
					visited[newA][newB]++;
					New.a = newA; New.b = newB; New.move = now.move; New.num = now.num;
					temp.push_back(New);
				}
			}
			int length = temp.size();
			for (int i = 0; i < length; i++)
			{
				virus t = temp[i];
				if (visited[t.a][t.b] > 1)
				{
					for (int j = 0; j < length; j++)
					{
						if (t.a == temp[j].a&&t.b == temp[j].b&&t.num < temp[j].num&&i != j)
						{
							Map[t.a][t.b] += temp[i].num;
							temp[i].num = 0;
						}
					}
				}
			}

			for (int i = 0; i < length; i++)
			{
				virus t = temp[i];
				if (t.num != 0)
				{
					t.num += Map[t.a][t.b];
					BFS.push_back(t);
				}
			}
			Time++;
		}
		int ans = 0;
		for (int i = 0; i < BFS.size(); i++)
		{
			ans += BFS[i].num;
		}
		cout << "#" << test_case << " " << ans << endl;

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}