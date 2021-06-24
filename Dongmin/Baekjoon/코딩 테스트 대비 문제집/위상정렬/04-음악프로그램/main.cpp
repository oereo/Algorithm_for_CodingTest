#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<int> indegree(N+1, 0);
    vector<vector<int> > graph(N+1, vector<int>());

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;

        int p, v; 
        cin >> p;
        for (int j = 0; j < k-1; j++) {
            cin >> v;
            graph[p].push_back(v);
            indegree[v]++;
            p = v;
        }
    }

    vector<int> order;
    queue<int> qu;
    for (int i = 1; i < N+1; i++) {
        if (indegree[i] == 0) qu.push(i);
    }
    
    while (!qu.empty()) {
        int s = qu.front();
        order.push_back(s);
        qu.pop();
        
        int len = graph[s].size();
        for (int i = 0; i < len; i++) {
            int v = graph[s][i];
            indegree[v]--;
            if (indegree[v] == 0) qu.push(v);
        }
    }
    
    if (order.size() != N) {
        cout << 0 << '\n';
        return 0;
    }

    for (int v : order) {
        cout << v << '\n';
    }
    return 0;
}