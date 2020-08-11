#include <vector>
#include<iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int Map[11][11];
struct loc {
	int a; int b;
	int wStair = 0;

};
vector<loc> people;
vector<loc> stair;
int ans = 9999999;
int timeCheck(int len)
{
	deque<int> timeStep[2];
	int s_len1 = stair[0].wStair;
	int s_len2 = stair[1].wStair;
	for (int i = 0; i < len; i++)
	{
		int t = abs(people[i].a - stair[people[i].wStair - 1].a) + abs(people[i].b - stair[people[i].wStair - 1].b);
		timeStep[people[i].wStair - 1].push_back(t);
	}
	sort(timeStep[0].begin(), timeStep[0].end());
	sort(timeStep[1].begin(), timeStep[1].end());
	deque<int> f_s;
	int t1 = 1;
	while (1)
	{

		for (int i = 0; i < f_s.size(); i++)
		{
			f_s[i]--;
		}
		while (1)
		{
			if (f_s.size() > 0 && f_s.front() == 0)
			{
				f_s.pop_front();
			}
			else break;
		}

		while (1)
		{
			if (timeStep[0].size() > 0 && t1 >= timeStep[0].front())
			{
				if (f_s.size() >= 3)
				{
					break;
				}
				else {
					f_s.push_back(s_len1);
					timeStep[0].pop_front();
				}
			}
			else { break; }
		}
		if (timeStep[0].size() == 0 && f_s.size() == 0)
		{
			break;
		}
		t1++;
	}
	int t2 = 1;
	while (1)
	{
		for (int i = 0; i < f_s.size(); i++)
		{
			f_s[i]--;
		}
		while (1)
		{
			if (f_s.size() > 0 && f_s.front() == 0)
			{
				f_s.pop_front();
			}
			else break;
		}
		while (1)
		{
			if (timeStep[1].size() > 0 && t2 >= timeStep[1].front())
			{
				if (f_s.size() >= 3)
				{
					break;
				}
				else {
					f_s.push_back(s_len2);
					timeStep[1].pop_front();
				}
			}
			else { break; }
		}
		if (timeStep[1].size() == 0 && f_s.size() == 0) { break; }
		t2++;
	}

	return max(t1, t2);
}


void DFS(int num, int idx, int len)
{

	if (len == num)
	{
		int cmp = timeCheck(len);
		if (cmp < ans)
		{
			//for (int i = 0; i < len; i++)
			//{
			//	cout << people[i].wStair << " ";
			//}cout << endl;
			ans = min(ans, timeCheck(len));
		}
		return;
	}
	for (int i = idx; i < len; i++)
	{
		if (people[i].wStair == 0)
		{
			people[i].wStair = 1;
			DFS(num + 1, i, len);
			people[i].wStair = 2;
			DFS(num + 1, i, len);
			people[i].wStair = 0;
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int ptr = 0;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		int N;
		cin >> N;
		ans = 999999;
		memset(Map, 0, sizeof(Map));
		people.clear();
		stair.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
				if (Map[i][j] == 1)
				{
					loc t;
					t.a = i; t.b = j;
					people.push_back(t);
				}
				else if (Map[i][j] > 1)
				{
					loc t;
					t.a = i; t.b = j; t.wStair = Map[i][j];

					stair.push_back(t);
				}
			}
		}

		DFS(0, 0, people.size());
		cout << "#" << test_case << " " << ans + 1 << endl;
	}
	cin >> T;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}