#include <iostream>
#include <vector>

using namespace std;

int N, M, H, MIN;
vector<vector<int>> map;

bool check() {
	for (int i = 0; i < N; i++) {
		int a = i;
		for (int j = 0; j < H; j++) {
			if (map[j][a] == 1)
				a++;
			else if (map[j][a] == -1)
				a--;
		}
		if (a != i)
			return false;
	}
	return true;
}

void DFS(int x, int y, int cnt) {
	if (cnt >= MIN) return;
	if (check()) {
		MIN = cnt;
		return;
	}

	for (int i = x; i < H; i++) {
		for (int j = y; j < N - 1; j++) {
			if (map[i][j] != 0 || map[i][j + 1] != 0) continue;

			map[i][j] = 1;
			map[i][j + 1] = -1;

			DFS(i, j + 1, cnt + 1);

			map[i][j] = 0;
			map[i][j + 1] = 0;
		}
		y = 0;
	}
}

int main() {
	// 입력 받기
	cin >> N >> M >> H;
	map.assign(H, vector<int>(N));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = -1;
	}

	// 최소 횟수로 가로선 추가하기
	MIN = 4;
	DFS(0, 0, 0);
	if (MIN != 4)
		cout << MIN;
	else
		cout << -1;
}