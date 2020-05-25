#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int dR[4] = { 0, 1, 0, -1};
int dC[4] = { 1, 0, -1, 0};


int cnt = 0;

char puzzle[2001][2001] = { 0 };
char puzzle_temp[2001][2001] = { 0 };

int main() {
	int M = 0;
	int N = 0;

	
	//puzzle.assign(M, vector<char>(N, 0));
	//wall.assign(M, vector<int>(N, 0));
	//cout << "ddd";
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> puzzle[i][j];
			puzzle_temp[i][j] = puzzle[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((puzzle[i][j] == 'W') || (puzzle_temp[i][j] == 'O') && puzzle[i][j] == 'W') {
				for (int k = 0; k < 4; k ++ ) {
					if(i+dR[k]<0 || i+dR[k]>=N || i+dC[k] < 0 || i+dC[k] >=M )
					puzzle_temp[i + dR[k]][j + dC[k]] = 'O';
				}
				
				//DFS(puzzle[i][j], i, j);
			}
		}
	}

	for(int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (puzzle_temp[i][j] == 'B') {
				cnt++;
				
			}
			//cout << puzzle_temp[i][j];
		}
		//cout << "\n";
	}

	//cout << cnt<< "\n";
	long result = 1;

	for (int i = 0; i < cnt; i++) {
		result = (result * 2) % 1000000007;
	}
	//result = pow(2, cnt) % 1000000007;
	cout << result % 1000000007;
	return 0;
}