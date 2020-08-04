#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
typedef struct work {
    int num;
    int remainedTime;
} work;

bool cmp(const work &w1, const work &w2){
    if(w1.remainedTime < w2.remainedTime){
        return true;
    }
    else if(w1.remainedTime == w2.remainedTime){
        return w1.num < w2.num;
    }
    else{
        return false;
    }
}

int N, K;
vector<vector<int> > graph;
vector<bool> completeWork;
vector<int> completeTime;
vector<int> inedges;
vector<int> needed;
vector<int> visited;

int target;

void getInput() {
    cin >> N >> K;
    graph.assign(N+1, vector<int>(N+1, 0));
    inedges.assign(N+1, 0);
    completeTime.assign(N+1, 0);
    completeWork.assign(N+1, false);
    visited.assign(N+1, false);
    for(int i=1; i<=N; i++) {
        cin >> completeTime[i];
    }

    int start, end;
    for(int i=0; i<K; i++) {
        cin >> start >> end;
        inedges[end] += 1;
        graph[start][end] = 1;
    }
    cin >> target;
}
void findNeededBuliding() {
    queue<int> nq;
    nq.push(target);
    needed.push_back(target);
    visited[target] = true;

    while(!nq.empty()) {
        int num = nq.front();
        nq.pop();
        for(int i=1; i<=N; i++) {
            if(graph[i][num]) {
                if(!visited[i] ) {
                    nq.push(i);
                    needed.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
}
void completeTransaction(int nodenum) {
    for(int i=1; i<=N; i++) {
        if(graph[nodenum][i] == 1) {
            graph[nodenum][i] = 0;
            inedges[i] -= 1;
        }
    }
    completeWork[nodenum] = true;
}

void solution() {
    int time = 0;
    findNeededBuliding();
    
    deque<work> working;
    for(int i=1; i<=N; i++) {
        if(inedges[i] == 0) {
            working.push_back({i, completeTime[i]});
            inedges[i] = -1;
        }
    }

    while(!completeWork[target]) {
        sort(working.begin(), working.end(), cmp);
        work cw = working.front();
        working.pop_front();
        for(int i=0; i<working.size(); i++) {
            working[i].remainedTime -= cw.remainedTime;
        }
        time += cw.remainedTime;
        //printf("#%d work completed, time %d elapsed\n", cw.num, time);

        completeTransaction(cw.num);
        for(int i=1; i<=N; i++) {
            if(inedges[i] == 0) {
                working.push_back({i, completeTime[i]});
                inedges[i] = -1;
                //printf("#%d work added\n", i);
            }
        }
    }

    printf("%d\n", time);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution();
	}
	return 0;
}