#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int>& V, vector<vector<int>> C) {
    int n = V.size();
    for(int i = 0; i < n; i++) {
        if(C[start][i] == 1 && V[i] == 0){
            V[i] = 1;
            dfs(i, V, C);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(i, visited, computers);
            answer++;
        }
    }
    return answer;
}
