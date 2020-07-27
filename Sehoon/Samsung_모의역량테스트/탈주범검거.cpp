#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int map[51][51] = {};
int visited[51][51] = {0};
int dx[4] = { -1, 0, 1, 0 }; // 북, 서, 남, 동
int dy[4] = { 0, -1, 0, 1 };
int cnt;
int result;
void BFS(int x, int y, int N, int M, int L) {

	queue< pair<int, int> > q; 
	q.push(make_pair(x, y)); 

	
	visited[x][y] = 1;
	

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (visited[x][y] == L) {
			break;
			//cout << result;
		}
		//cnt++;

		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (i == 0) {
				if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[nx][ny] == 7) { // 기준 북에서 남으로
					if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6) {
						if (0 <= nx && nx < N && 0 <= ny && ny < M) {

							if (visited[nx][ny] == 0 && map[nx][ny] != 0) {
								visited[nx][ny] = visited[x][y] + 1;

								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			if (i == 1) {//서에서 동으로 
				if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7) {
					if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5) {
						if (0 <= nx && nx < N && 0 <= ny && ny < M) {

							if (visited[nx][ny] == 0 && map[nx][ny] != 0) {
								visited[nx][ny] = visited[x][y] + 1;

								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			if (i == 2) {//남에서 북으로 
				if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6) {
					if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7) {
						if (0 <= nx && nx < N && 0 <= ny && ny < M) {

							if (visited[nx][ny] == 0 && map[nx][ny] != 0) {
								visited[nx][ny] = visited[x][y] + 1;

								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			if (i == 3) {//동에서 서으로 
				if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5) {
					if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7) {
						if (0 <= nx && nx < N && 0 <= ny && ny < M) {

							if (visited[nx][ny] == 0 && map[nx][ny] != 0) {
								visited[nx][ny] = visited[x][y] + 1;

								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M, R, C, L = 0;
	
	
	freopen("sample_input (4).txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}

		BFS(R, C, N, M, L);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] != 0) {
					result++;
				}
				cout << visited[i][j]<<" ";
			}
			cout << endl;
		}
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cout << result << endl;
		result = 0;
		cout << endl;

		
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}