#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;

int find(int node)
{
    if (parent[node] == node)
        return node;
    else
        return parent[node] = find(parent[node]);
}

int solution(int n, vector<vector<int>> edges)
{
    // 시간 단축
    int len = edges.size();
    vector<int> count(n + 1, len);
    for (int i = 0; i < len; i++)
    {
        count[edges[i][0]]--;
        count[edges[i][1]]--;
    }

    // 간선 정리 및 정렬
    for (int i = 0; i < len; i++)
    {
        if (edges[i][0] > edges[i][1])
            swap(edges[i][0], edges[i][1]);
    }
    sort(edges.begin(), edges.end());

    // 각 노드의 부모 노드 초기화
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> temp;
    temp = parent;

    // 각 노드가 없다고 가정하고 사이클 여부 판단
    int answer = 0;
    for (int i = 1; i <= n; i++)
    { // i : 제외할 노드
        if (count[i] > n - 2)
            continue;
        parent = temp;
        bool check = false; // 사이클 존재 여부
        for (int j = 0; j < len; j++)
        {
            if (edges[j][0] == i || edges[j][1] == i)
                continue;
            // 연결된 두 노드의 루트 노드가 다르면 연결
            int a_root = find(edges[j][0]);
            int b_root = find(edges[j][1]);
            if (a_root != b_root)
            {
                if (a_root < b_root)
                    parent[b_root] = a_root;
                else
                    parent[a_root] = b_root;
            }
            // 루트 노드가 같으면 사이클 존재
            else
            {
                check = true;
                break;
            }
        }
        if (!check)
            answer += i;
    }
    return answer;
}