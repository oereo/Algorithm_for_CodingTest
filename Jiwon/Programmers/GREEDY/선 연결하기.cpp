/*
n개의 섬 사이에 다리를 건설하는 비용(costs)이 주어질 때, 
최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용을 return 하도록 solution을 완성하세요.

다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다. 
예를 들어 A 섬과 B 섬 사이에 다리가 있고, B 섬과 C 섬 사이에 다리가 있으면 A 섬과 C 섬은 서로 통행 가능합니다.

임의의 i에 대해, costs[i][0] 와 costs[i] [1]에는 다리가 연결되는 두 섬의 번호가 들어있고, 
costs[i][2]에는 이 두 섬을 연결하는 다리를 건설할 때 드는 비용입니다.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[101];

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++){ 
        d[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end){
            d[start] = end;
            answer += cost;
        }
    }
    
    return answer;
}