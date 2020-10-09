#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct {
    int end;
    int cost;
} Edge;

int N, M ,X;
vector<vector<Edge> > edges;
int out_cost[1001];
int in_cost[1001];

void getInput() {
    cin >> N >> M >> X;
    edges.assign(N+1, vector<Edge>());
    for(int i=0; i<M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edges[start].push_back(Edge{end, cost});
    }
}

void dijkstra(int start) {
    int dp[1001];
    memset(dp, -1, sizeof(dp));

    queue<Edge> q;
    q.push({start,0});
    dp[start] = 0;
    while(!q.empty()) {
        Edge here = q.front();
        q.pop();

        for(int i=0; i<edges[here.end].size(); i++) {
            int dest = edges[here.end][i].end;
            int new_cost = here.cost + edges[here.end][i].cost;
            if(dp[dest] < 0 || dp[dest] > new_cost) {
                q.push({dest, new_cost});
                dp[dest] = new_cost;
            }
        }
    }

    if(start == X) {
        for(int i=1; i<=N; i++) {
            in_cost[i] = dp[i];
        }
    }
    else {
        out_cost[start] = dp[X];
    }
}


void solution() {
    int ans = 0;
    for(int i=1; i<=N; i++) {
        dijkstra(i);
    }

    for(int s=1; s<=N; s++) {
        if(s == X) continue;
        int total = in_cost[s] + out_cost[s];
        if(total > ans) ans = total;
    }

    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}