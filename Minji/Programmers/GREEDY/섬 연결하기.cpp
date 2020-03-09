#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> graph(n,vector<int>(n));
    int len = costs.size();
    for(int i = 0; i < len; i++){
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    vector<int> visited;  // 방문 한 곳
    visited.push_back(0);
    vector<int> unvisited; // 방문 하지 않은 곳
    for(int i = 1; i < n; i++){
        unvisited.push_back(i);
    }
    while(visited.size() != n){
        int min = 10000000;
        int min_index = 0;
        for(int i = 0; i < visited.size(); i++){
            for(int j = 0; j < unvisited.size(); j++){
                if(graph[visited[i]][unvisited[j]] > 0
                   && min > graph[visited[i]][unvisited[j]]){
                    min = graph[visited[i]][unvisited[j]];
                    min_index = j;
                }
            }
        }
        visited.push_back(unvisited[min_index]);
        unvisited.erase(unvisited.begin() + min_index);
        answer += min;
    }
    return answer;
}