#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;

vector<vector<int>> map;
vector<vector<int>> visit;
vector<int> res;

void dfs( int i ,vector<vector<int>> &edge, vector<vector<int>> &map, vector<vector<int>> &visit, int n, int cnt_1){
    cnt_1++;
    
    //cnt_1 = max(cnt, cnt_1);
    
    
    //visit[i][k] = 1;
    for(int k = 0; k<n+1; k++){
        if(map[i][k] == 1 && visit[i][k] == 0){
            visit[i][k] = 1;
            cnt++;
            dfs(k, edge, map, visit, n, cnt);
             //cnt++;
            
        }
       res.push_back(cnt_1); 
        
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer;
    //int col = 2;
    map.assign(n+1, vector<int>(n+1,0));
    visit.assign(n+1, vector<int>(n+1,0));
    for(int i = 0; i<n; i++){
      
            map[edge[i][0]][edge[i][1]] = 1;
            map[edge[i][1]][edge[i][0]] = 1;
            visit[edge[i][0]][edge[i][1]] = 1;
            visit[edge[i][1]][edge[i][0]] = 1;
            //cnt = 0;
            dfs(map[edge[i][0]][edge[i][1]], edge, map, visit, n, cnt);
           
    }
    
    answer = res[0];
    
    return answer;
}