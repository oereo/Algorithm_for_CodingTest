#include <vector>
#include <queue>
using namespace std;

struct Robot {
    int move;
    int dir;
    int x;
    int y;
};

int solution(vector<vector<int>> board) {
    int len = board.size();
    int dir1[4][2] = {{0, 2}, {1, 0}, {0, -1}, {-1, 0}};
    int dir2[4][2] = {{2, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int MIN[100][100][2];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < 2; k++) {
                MIN[i][j][k] = 987654321;
            }
        }
    }
    MIN[0][0][0] = 0;

    queue<Robot> q;
    q.push({0, -1, 0, 0});
    while (!q.empty()) {
        Robot now = q.front();
        q.pop();
        if (now.dir == -1) { // 가로 방향
            if (now.x == len - 1 && now.y == len - 2)
                return now.move;
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dir1[i][0];
                int ny = now.y + dir1[i][1];
                if (nx < 0 || ny < 0 || nx >= len || ny >= len || board[nx][ny] == 1)
                    continue;
                switch (i) {
                case 0:
                    if (MIN[nx][ny - 1][0] > now.move + 1) {
                        MIN[nx][ny - 1][0] = now.move + 1;
                        q.push({now.move + 1, now.dir, nx, ny - 1});
                    }
                    break;
                case 1:
                    if (board[nx][ny + 1] == 0) {
                        if (MIN[now.x][now.y][1] > now.move + 1) {
                            MIN[now.x][now.y][1] = now.move + 1;
                            q.push({now.move + 1, -now.dir, now.x, now.y});
                        }
                        if (MIN[now.x][now.y + 1][1] > now.move + 1) {
                            MIN[now.x][now.y + 1][1] = now.move + 1;
                            q.push({now.move + 1, -now.dir, now.x, now.y + 1});
                        }
                        if (MIN[nx][ny][0] > now.move + 1) {
                            MIN[nx][ny][0] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        }
                    }
                    break;
                case 2:
                    if (MIN[nx][ny][0] > now.move + 1) {
                        MIN[nx][ny][0] = now.move + 1;
                        q.push({now.move + 1, now.dir, nx, ny});
                    }
                    break;
                case 3:
                    if (board[nx][ny + 1] == 0) {
                        if (MIN[nx][ny][1] > now.move + 1) {
                            MIN[nx][ny][1] = now.move + 1;
                            q.push({now.move + 1, -now.dir, nx, ny});
                        }
                        if (MIN[nx][ny + 1][1] > now.move + 1) {
                            MIN[nx][ny + 1][1] = now.move + 1;
                            q.push({now.move + 1, -now.dir, nx, ny + 1});
                        }
                        if (MIN[nx][ny][0] > now.move + 1) {
                            MIN[nx][ny][0] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        }
                    }
                    break;
                }
            }
        }
        else { // 세로 방향
            if (now.x == len - 2 && now.y == len - 1)
                return now.move;
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dir2[i][0];
                int ny = now.y + dir2[i][1];
                if (nx < 0 || ny < 0 || nx >= len || ny >= len || board[nx][ny] == 1)
                    continue;
                switch (i) {
                case 0:
                    if (MIN[nx - 1][ny][1] > now.move + 1) {
                        MIN[nx - 1][ny][1] = now.move + 1;
                        q.push({now.move + 1, now.dir, nx - 1, ny});
                    }
                    break;
                case 1:
                    if (board[nx + 1][ny] == 0) {
                        if (MIN[nx][ny][0] > now.move + 1) {
                            MIN[nx][ny][0] = now.move + 1;
                            q.push({now.move + 1, -now.dir, nx, ny});
                        }
                        if (MIN[nx + 1][ny][0] > now.move + 1) {
                            MIN[nx + 1][ny][0] = now.move + 1;
                            q.push({now.move + 1, -now.dir, nx + 1, ny});
                        }
                        if (MIN[nx][ny][1] > now.move + 1) {
                            MIN[nx][ny][1] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        }
                    }
                    break;
                case 2:
                    if (MIN[nx][ny][1] > now.move + 1) {
                        MIN[nx][ny][1] = now.move + 1;
                        q.push({now.move + 1, now.dir, nx, ny});
                    }
                    break;
                case 3:
                    if (board[nx + 1][ny] == 0) {
                        if (MIN[now.x][now.y][0] > now.move + 1) {
                            MIN[now.x][now.y][0] = now.move + 1;
                            q.push({now.move + 1, -now.dir, now.x, now.y});
                        }
                        if (MIN[now.x + 1][now.y][0] > now.move + 1) {
                            MIN[now.x + 1][now.y][0] = now.move + 1;
                            q.push({now.move + 1, -now.dir, now.x + 1, now.y});
                        }
                        if (MIN[nx][ny][1] > now.move + 1) {
                            MIN[nx][ny][1] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        }
                    }
                    break;
                }
            }
        }
    }
}