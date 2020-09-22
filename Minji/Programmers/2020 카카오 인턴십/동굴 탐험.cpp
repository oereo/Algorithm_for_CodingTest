#include <vector>
#include <queue>
using namespace std;

vector<int> bi_graph[200000];
vector<int> uni_graph[200000];
vector<bool> visit;
vector<bool> finish;
bool answer = true;

void DFS(int start)
{
    if (answer == false)
        return;

    visit[start] = 1;
    for (auto next : uni_graph[start])
    {
        if (visit[next] == 0)
            DFS(next);
        else if (finish[next] == 0)
        {
            answer = false;
            return;
        }
    }
    finish[start] = 1;
    return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order)
{
    // 양방향 그래프
    for (auto p : path)
    {
        bi_graph[p[0]].push_back(p[1]);
        bi_graph[p[1]].push_back(p[0]);
    }

    // 단방향 그래프
    queue<int> q;
    q.push(0);
    visit.assign(n, 0);
    visit[0] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto t : bi_graph[now])
        {
            if (visit[t] != 0)
                continue;
            visit[t] = 1;
            uni_graph[now].push_back(t);
            q.push(t);
        }
    }
    for (auto o : order)
    {
        if (o[1] == 0)
            return false;
        uni_graph[o[0]].push_back(o[1]);
    }

    // 사이클 존재 유무 판단
    visit.assign(n, 0);
    finish.assign(n, 0);
    DFS(0);

    return answer;
}