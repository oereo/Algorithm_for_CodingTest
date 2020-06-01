#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;


int main() {
	// 입력 받기
	cin >> N >> M;
	map.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				house.push_back({ i,j });
			}
			else if (a == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	// 치킨집 선정 & 최단 거리 구하기
	int chicken_len = chicken.size();
	int house_len = house.size();
	int MIN = 987654321;
	int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<int> idx(chicken_len);
	for (int i = 0; i < M; i++) {
		idx[chicken_len - 1 - i] = 1;
	}

	do {
		int sum = 0;
		for (int i = 0; i < house_len; i++)	{
			int MIN_distance = 987654321;
			for (int j = 0; j < chicken_len; j++) {
				if (idx[j]) {
					int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					if (MIN_distance > distance)
						MIN_distance = distance;
				}
			}
			sum += MIN_distance;
		}
		if (MIN > sum)
			MIN = sum;
	} while (next_permutation(idx.begin(), idx.end()));

	cout << MIN;
}