#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Shark {
	int n;
	int x;
	int y;
	int d;
};

int main() {
	// 입력 받기 & 상어 저장
	int M, N, k;
	int board[20][20];
	int smell[20][20];
	bool visit[20][20];
	int total = 0;
	map<int, Shark> sharks;
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			smell[i][j] = k + 1;
			if (board[i][j] != 0) {
				sharks[board[i][j]] = { board[i][j], i,j, 0 };
				total++;
			}
		}
	}
	for (int i = 1; i <= total; i++) {
		cin >> sharks[i].d;
	}

	// 상어들의 우선순위 방향 저장
	int dirs[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };	// 상하좌우
	int priority_dirs[401][5][5];
	for (int a = 1; a <= total; a++) {
		for (int b = 1; b <= 4; b++) {
			for (int c = 1; c <= 4; c++) {
				cin >> priority_dirs[a][b][c];
			}
		}
	}

	// 상어 이동
	queue<Shark> q;
	for (auto shark : sharks)
		q.push(shark.second);
	int time = 0;
	while (1) {
		memset(visit, 0, sizeof(visit));

		if (total == 1) break;
		if (time == 1000) {
			time = -1;
			break;
		}

		// 냄새 시간 감소
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (smell[i][j] != 0) {
					smell[i][j]--;
					if (smell[i][j] == 0) board[i][j] = 0;
				}
			}
		}

		// 상어 이동
		int temp = total;
		for (int t = 0; t < total; t++) {
			bool check = false;
			Shark now = q.front(); q.pop();
			
			// 빈 곳 탐색
			for (int i = 1; i <= 4; i++) {
				int nd = priority_dirs[now.n][now.d][i];
				int nx = now.x + dirs[nd][0], ny = now.y + dirs[nd][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (board[nx][ny] == 0) {
					check = true;
					board[nx][ny] = now.n;
					visit[nx][ny] = 1;
					smell[nx][ny] = k + 1;
					q.push({ now.n, nx, ny, nd });
					break;
				}
				else if (visit[nx][ny] && board[nx][ny] != 0) {
					check = true;
					temp--;
					break;
				}
			}
			if (check) continue;

			// 자신의 냄새 탐색
			for (int i = 1; i <= 4; i++) {
				int nd = priority_dirs[now.n][now.d][i];
				int nx = now.x + dirs[nd][0], ny = now.y + dirs[nd][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (board[nx][ny] == now.n) {
					smell[nx][ny] = k + 1;
					q.push({ now.n, nx, ny, nd });
					break;
				}
			}
		}

		time++;
		total = temp;
	}

	cout << time;
}