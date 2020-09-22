#include <vector>
#include <queue>

using namespace std;

vector<int> graph[200000];
vector<vector<int>> order_copy;
vector<int> parent;
vector<bool> visit;
int len;

void DFS(int from, int to)
{
    if (from == to)
        return;

    // 방문해야 할 노드
    for (int i = 0; i < len; i++)
    {
        if (from == order_copy[i][1] && visit[order_copy[i][0]] == 0)
        {
            visit[order_copy[i][0]] = 1;
            DFS(order_copy[i][0], to);
        }
    }

    // 부모 노드
    if (parent[from] != 0 && visit[parent[from]] == 0)
    {
        visit[parent[from]] = 1;
        DFS(parent[from], to);
    }

    return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order)
{
    // 그래프 입력 받기
    for (int i = 0; i < n - 1; i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }

    // 부모 노드 구하기
    parent.assign(n, 0);
    visit.assign(n, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visit[now] = 1;
        for (int a : graph[now])
        {
            if (visit[a] == 1)
                continue;
            parent[a] = now;
            q.push(a);
        }
    }

    // 탐험 가능 여부 판단 - DFS
    bool answer = true;
    len = order.size();
    order_copy = order;
    for (int i = 0; i < len; i++)
    {
        visit.assign(n, 0);
        visit[0] = 1;
        visit[order[i][0]] = 1;
        DFS(order[i][0], order[i][1]);
        if (visit[order[i][1]] == 1)
            return false;
    }
    return answer;
}