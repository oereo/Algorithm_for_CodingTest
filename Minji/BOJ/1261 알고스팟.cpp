#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct pos {
	int x;
	int y;
};

int main() {
	int map[100][100];
	int destroy[100][100];
	int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			map[i][j] = a[j] - '0';
			destroy[i][j] = 987654321;
		}
	};

	queue<pos> q;
	int x, y, nx, ny;
	destroy[0][0] = 0;
	q.push({ 0,0 });
	while (!q.empty()) {
		x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 0) {
				if (destroy[nx][ny] > destroy[x][y]) {
					destroy[nx][ny] = destroy[x][y];
					q.push({ nx,ny });
				}
			}
			else {
				if (destroy[nx][ny] > destroy[x][y] + 1) {
					destroy[nx][ny] = destroy[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << destroy[N - 1][M - 1];
}