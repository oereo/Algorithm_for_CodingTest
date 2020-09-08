#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int visited[16];
int visited_cp[16];
int Map[200];
int Map_cp[200];
int lenW; int lenD;
bool findAns = false;
int ANSWER = -1;
int N;
bool desc(int a, int b) { return a > b; }
void DFS(int tar, int num, int who, int ans, vector<int> dist, vector<int> weak)
{
	if (findAns) { return; }
	if (ans == lenW)
	{
		findAns = true;
		ANSWER = num;
		return;
	}
	if (tar == num) { return; }
	int visited_cp[16];
	memcpy(visited_cp, visited, sizeof(visited));
	for (int i = who + 1; i < lenD; i++) // 어떤사람 투입하는가
	{
		if (findAns) { return; }
		for (int j = 0; j < lenW; j++) // 어느 취약점 위치에 투입하는가
		{
			if (findAns) { return; }
			if (visited[j] == 0)
			{
				int fix = ans;
				for (int k = 0; k < lenW; k++) //거기서 부터 얼마나 가는가(시계)
				{
					if (visited[k] == 0)
					{
						if (weak[j] + dist[i] < N)
						{
							if (weak[k] >= weak[j] && weak[k] <= weak[j] + dist[i])
							{
								fix++;
								visited[k] = 1;
							}
							else if (weak[k] > weak[j] + dist[i]) { continue; }
						}
						else if (weak[j] + dist[i] >= N)
						{
							if (!(weak[k] > (weak[j] + dist[i] - N) && weak[k] < weak[j]))
							{
								fix++;
								visited[k] = 1;
							}
						}
					}
				}
				DFS(tar, num + 1, i, fix, dist, weak); //시계방향 완료. 리셋 ㄱㄱ
				memcpy(visited, visited_cp, sizeof(visited));
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	N = n;
	lenW = weak.size();
	sort(dist.begin(), dist.end(), desc);

	lenD = dist.size();
	for (int per = 1; per <= lenD; per++) //투입 사람수 = ans
	{
		if (findAns) { return ANSWER; }
		for (int i = 0; i < lenD; i++) // 어떤사람 투입하는가
		{
			for (int j = 0; j < lenW; j++) // 어느 취약점 위치에 투입하는가
			{
				int fix = 0;
				for (int k = 0; k < lenW; k++) //그 범위안에 얼마나 포함되는가
				{
					if (weak[j] + dist[i] < N)
					{
						if (weak[k] >= weak[j] && weak[k] <= weak[j] + dist[i])
						{
							fix++;
							visited[k] = 1;
						}
					}
					else if (weak[j] + dist[i] >= N)
					{
						if (!(weak[k] > (weak[j] + dist[i] - N) && weak[k] < weak[j]))
						{
							fix++;
							visited[k] = 1;
						}
					}
				}
				DFS(per, 1, i, fix, dist, weak); //시계방향 완료. 리셋 ㄱㄱ
				if (findAns) { return ANSWER; }
				memcpy(visited, visited_cp, sizeof(visited));
			}
		}

	}
	return ANSWER;
}