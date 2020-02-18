#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph;
    graph.assign(n, vector<int>(n, 0));
    int lines = edge.size();
    for(int i = 0; i < lines; i++){
        graph[edge[i][0]-1][edge[i][1]-1] = 1;
        graph[edge[i][1]-1][edge[i][0]-1] = 1;
    }
    vector<int> distance(n);
    vector<int> visited(n);
    visited[0] = 1;
    vector<int> visit(1);
    vector<int> temp;
    int count = 1;
    while(1){
        for(int i: visit){
            for(int j = 1; j < n; j++){
                if(graph[i][j] == 1 && visited[j] == 0){
                    visited[j] = 1;
                    temp.push_back(j);
                    distance[j] = count;
                }
            }
        }
        
        if(accumulate(visited.begin(),visited.end(),0) == n){
            return temp.size();
        }
                
        visit = temp;
        temp.clear();
        count++;
    }
}
