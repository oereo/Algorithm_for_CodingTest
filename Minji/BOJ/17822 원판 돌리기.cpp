#include <iostream>
#include <cstring>
using namespace std;

int N, M, T;
int board[51][51];
bool visit[51][51];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

bool remove(int x, int y, int v) {
	bool check = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = (y + dir[i][1] + M) % M;
		if (nx == 0 || nx > N) continue;
		if (board[nx][ny] == v && !visit[nx][ny]) {
			visit[nx][ny] = 1;
			check = true;
			board[nx][ny] = 0;
			remove(nx, ny, v);
		}
	}
	return check;
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int x, d, k, total, cnt;
	for (int a = 0; a < T; a++) {
		// 원판 회전
		cin >> x >> d >> k;
		if (d == 0) d = -1;
		for (int b = 1; b * x <= N; b++) {
			int temp[51];
			for (int c = 0; c < M; c++) {
				temp[(c + M - k * d) % M] = board[b * x][c];
			}
			memcpy(board[b * x], temp, sizeof(temp));
		}

		// 인접 숫자 제거
		bool check = true;
		total = 0, cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0) continue;
				visit[i][j] = 1;
				if (remove(i, j, board[i][j])) {
					board[i][j] = 0;
					check = false;
				}
				else {
					cnt++;
					total += board[i][j];
				}
			}
		}

		// 없는 경우
		if (check) {
			float avg = (float) total / cnt;
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] == 0) continue;
					if (board[i][j] > avg) {
						board[i][j]--;
						total--;
					}
					else if (board[i][j] < avg) {
						board[i][j]++;
						total++;
					}
				}
			}
		}
	}

	cout << total;
}