#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N = 0;
//int map[100][100] = { 0 };
vector<vector<int> > map;
vector<int> visit;
int tmap[100][100] = { 0 };
vector<int> edge[1001];
bool isVisit[1001];
int verNum = 1;
int visitCnt = 0;


void input() {

	cin >> N;
	map.assign(N, vector<int>(N, 0));
	visit.assign(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			
			
		}
	}
	
	
	
}





void DFS(int currVertex) {

	

	//visitCnt++;

	for (int i = 0; i < N; i++) {
		if (map[currVertex][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			DFS(i);
		}


	}


		
}


void output() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}




int main() {
	input();
	
	for (int i = 0; i < N; i++) {
		fill(visit.begin(), visit.end(), 0);
		DFS(i);

		for (int j = 0; j < N; j++) {
			if (visit[j] == 1)
				map[i][j] = 1;
		}
	}

	output();

	
	