#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// 입력 받기
	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// BFS : 0 가로, 1 대각선, 2 세로
	int answer = 0;
	queue<vector<int>> q;
	q.push({ 0,1,0 });
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int d = q.front()[2];
		q.pop();
		if (x == N - 1 && y == N - 1) {
			answer++;
			continue;
		}
		if (d == 0) {
			if (y + 1 < N && map[x][y + 1] == 0)
				q.push({ x, y + 1, 0 });
			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] == 0 && map[x][y + 1] == 0 && map[x + 1][y] == 0)
				q.push({ x + 1, y + 1, 1 });
		}
		else if (d == 1) {
			if (y + 1 < N && map[x][y + 1] == 0)
				q.push({ x, y + 1, 0 });
			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] == 0 && map[x][y + 1] == 0 && map[x + 1][y] == 0)
				q.push({ x + 1, y + 1, 1 });
			if (x + 1 < N && map[x + 1][y] == 0)
				q.push({ x + 1, y, 2 });
		}
		else {
			if (x + 1 < N && y + 1 < N && map[x + 1][y + 1] == 0 && map[x][y + 1] == 0 && map[x + 1][y] == 0)
				q.push({ x + 1, y + 1, 1 });
			if (x + 1 < N && map[x + 1][y] == 0)
				q.push({ x + 1, y, 2 });
		}
	}
	
	cout << answer;
}