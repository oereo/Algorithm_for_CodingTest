#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct block {
	int x;
	int y;
	int p;
};

int N, W, H;
int board[15][12];
int temp_board[5][15][12];
int dir[4][2] = { {-1, 0},{0,1},{1,0},{0,-1} };
int down[15];
queue<block> q;
int MIN;

void shoot(int i, int cnt) {
	for (int j = 0; j < H; j++) {
		if (temp_board[cnt][j][i] == 0) continue;
		if (temp_board[cnt][j][i] == 1)
			temp_board[cnt][j][i] = 0;
		else
			q.push({ j, i, temp_board[cnt][j][i] - 1 });
		break;
	}
	if (q.empty()) return;

	int x, y, p, nx, ny;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, p = q.front().p, q.pop();
		temp_board[cnt][x][y] = 0;
		for (int a = 0; a < 4; a++) {
			nx = x, ny = y;
			for (int b = 0; b < p; b++)	{
				nx += dir[a][0];
				ny += dir[a][1];
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				if (temp_board[cnt][nx][ny] <= 1)
					temp_board[cnt][nx][ny] = 0;
				else
					q.push({ nx, ny, temp_board[cnt][nx][ny] - 1 });
			}
		}
	}

	// 빈공간 제거
	for (int a = 0; a < W; a++) {
		memset(down, 0, sizeof(down));
		int move = 0;
		for (int b = H-1; b >= 0; b--) {
			if (temp_board[cnt][b][a] == 0) {
				move++;
			}
			else if(move != 0) {
				down[b] = move;
			}
		}
		for (int b = H - 1; b >= 0; b--) {
			if (down[b] != 0) {
				temp_board[cnt][b + down[b]][a] = temp_board[cnt][b][a];
				temp_board[cnt][b][a] = 0;
			}
		}
	}
}

void DFS(int cnt) {
	if (cnt == N) {
		// 남은 벽돌 개수 구하기
		int result = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (temp_board[cnt][i][j] != 0)
					result++;
			}
		}
		if (MIN > result)
			MIN = result;
		return;
	}

	memcpy(temp_board[cnt + 1], temp_board[cnt], sizeof(board));
	for (int i = 0; i < W; i++)	{
		shoot(i, cnt + 1);
		DFS(cnt + 1);
		memcpy(temp_board[cnt + 1], temp_board[cnt], sizeof(board));
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		// 입력 받기
		cin >> N >> W >> H;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
			}
		}

		// 벽돌 깨기
		MIN = 987654321;
		memcpy(temp_board[0], board, sizeof(board));
		DFS(0);

		cout << "#" << test_case << " " << MIN << "\n";
	}
	return 0;
}