#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    short id;
    int cost;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<Node> > graph (N+1, vector<Node>());
    vector<vector<Node> > inverseGraph (N+1, vector<Node>());
    vector<int> indegree(N+1, 0);
    vector<int> longest (N+1, 0);

    for (int i = 0; i < M; i++) {
        short from, to;
        int cost;
        cin >> from >> to >> cost;
        indegree[to]++;
        graph[from].push_back({to, cost});
        inverseGraph[to].push_back({from, cost});
    }
    
    short s, e;
    cin >> s >> e;
    queue<Node> qu;
    qu.push({s, 0});

    int longestCost = 0;
    while (!qu.empty()) {
        Node v = qu.front();
        qu.pop();
        if (v.id == e) {
            longestCost = max(longestCost, v.cost);
        }

        int len = graph[v.id].size();
        for (int i = 0; i < len; i++) {
            Node to = graph[v.id][i];
            int cost = v.cost + to.cost;
            if (longest[to.id] < cost) longest[to.id] = cost;
            if (--indegree[to.id] != 0) continue;
            qu.push({to.id, max(longest[to.id], cost)});
        }
    }

    queue<short> idqu;
    vector<bool> checked (N+1, false);
    int cnt = 0;
    idqu.push(e);
    while (!idqu.empty()) {
        short v = idqu.front();
        idqu.pop();

        int len = inverseGraph[v].size();
        for (int i = 0; i < len; i++) {
            Node next = inverseGraph[v][i];
            if (longest[v] - next.cost > longest[next.id]) continue;
            cnt++;
            if (checked[next.id]) continue;
            if (!checked[next.id]) checked[next.id] = true;
            idqu.push(inverseGraph[v][i].id);
        }  
    }

    cout << longestCost << "\n" << cnt << "\n";
    return 0;
}