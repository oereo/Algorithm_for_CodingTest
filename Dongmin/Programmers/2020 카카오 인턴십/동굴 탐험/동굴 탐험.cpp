// Decision Problem
// 데드락 문제: 사이클 존재?
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> alist[200000];
vector<int> dirList[200000];
int visitOrder[200000];
bool finished[200000];

bool hasCycle = false;
int cnt = 0;

void cycleCheck(int v) {
    if(hasCycle) return;

    visitOrder[v] = cnt++;
    for(int i=0; i<dirList[v].size(); i++) {
        int nv = dirList[v][i];
        if(visitOrder[nv] == -1) {
            cycleCheck(nv);
        }
        else if(visitOrder[v] < visitOrder[nv]) {
            // 이미 다른 경로로 탐색한 노드는 pruning
            continue;
        }
        else if(!finished[nv]){
            hasCycle = true;
            return;
        }
    }
    finished[v] = 1;
    return;
}

void makeDirGraph(int start, int parent) {
    for(int i=0; i<alist[start].size(); i++) {
        int nv = alist[start][i];
        if(nv != parent) {
            dirList[start].push_back(nv);
            makeDirGraph(nv, start);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(int i=0; i<n-1; i++) {
        alist[path[i][0]].push_back(path[i][1]);
        alist[path[i][1]].push_back(path[i][0]);
    }
    makeDirGraph(0, -1);

    for(int i=0; i<order.size(); i++) {
        dirList[order[i][0]].push_back(order[i][1]);
    }

    memset(visitOrder, -1, sizeof(visitOrder));
    memset(finished, 0, sizeof(finished));
    cycleCheck(0);
    answer = !hasCycle;
    return answer;
}