#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
int people1 = 0;
int people2 = 0;

int visitCnt = 0;
int currVertex = 0;
	
vector<vector<int> > map(101);


int startParents = 0;
int from,to = 0;
vector<int> edge[1001];
vector<int> isVisit(1001, 0);
queue<int> qu;
bool result = 0;





void goBFS(int people1, int people2) {
	//isVisit[people1] = true;
	qu.push(people1);
	
	while (!qu.empty()) {
		
			int currVertex = qu.front();
			qu.pop();
			
			if (currVertex == people2) {
				break;
			}
			
		// cout << currVertex << " ";
			for (int j = 0; j < edge[currVertex].size(); j++) {
				int nextVertex = edge[currVertex][j];
				if (!isVisit[nextVertex]) {
					isVisit[nextVertex] = isVisit[currVertex] + 1;
					
					qu.push(nextVertex);
				}
				
			}
			
		
	}
	if (isVisit[people2] != 0)
		cout << isVisit[people2] << endl;
	else
		cout << -1 << endl;

	
}


void goDFS(int currVertex, int endVertex) {
	
	cout << currVertex << endl;
	if (currVertex == endVertex) {
		cout << visitCnt;
		result =  true;
	}
	
	for (int i = 0; i < edge[currVertex].size(); i++) {
		int nextVertex = edge[currVertex][i];
		
		if (isVisit[nextVertex]) continue;
		
		isVisit[nextVertex] = true;
		visitCnt++;
		goDFS(nextVertex, endVertex);
	}


}

void input() {

	cin >> N >> people1 >> people2 >> M;

	for (int i = 0; i < M; i++) {

		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
		//map[from].push_back(to);
		//map[to].push_back(from);

	}
	
	//isVisit[people1] = true;

}


void output() {

	//goDFS(people1, people2);
	//if (!result) {
	//	cout << -1;
	//}
	goBFS(people1, people2);

	
}


int main() {

	input();
	output();
	
	return 0;
}