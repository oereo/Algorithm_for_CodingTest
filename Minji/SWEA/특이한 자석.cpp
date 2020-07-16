#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<deque<int>> magnet;
vector<bool> visit;
vector<int> nums;
vector<int> dirs;

void find(int num, int dir) {
	visit[num] = 1;
	nums.push_back(num);
	dirs.push_back(dir);
	if (num - 1 >= 0 && !visit[num - 1] && magnet[num - 1][2] != magnet[num][6])
		find(num - 1, -dir);
	if (num + 1 < 4 && !visit[num + 1] && magnet[num][2] != magnet[num + 1][6])
		find(num + 1, -dir);
}

void move() {
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		if (dirs[i] == 1) {
			magnet[nums[i]].push_front(magnet[nums[i]][7]);
			magnet[nums[i]].pop_back();
		}
		else {
			magnet[nums[i]].push_back(magnet[nums[i]][0]);
			magnet[nums[i]].pop_front();
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T, K;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		// 입력 받기
		cin >> K;
		magnet.assign(4, deque<int>(8));
		for (int i = 0; i < 4; i++)	{
			for (int j = 0; j < 8; j++)	{
				cin >> magnet[i][j];
			}
		}

		// 자석 이동
		for (int i = 0; i < K; i++)	{
			int num, dir;
			cin >> num >> dir;

			nums.clear();
			dirs.clear();
			visit.assign(4, 0);

			find(num - 1, dir);
			move();
		}

		// 점수 구하기
		int answer = 0;
		for (int i = 0; i < 4; i++)	{
			if (magnet[i][0])
				answer += (int) pow(2, i);
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}