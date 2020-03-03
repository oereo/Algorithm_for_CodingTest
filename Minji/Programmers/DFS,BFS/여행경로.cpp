#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> copy_tickets;
vector<string> answer;
vector<string> temp;
vector<bool> visited;

bool DFS(string start, int count, int len){
    temp.push_back(start);
    
    if(count == len){   // 모두 방문 시 DFS 종료
        answer = temp;
        return true;
    }
    for(int i = 0; i < len; i++){
        if(copy_tickets[i][0] == start && visited[i] == false){
            visited[i] = true;
            if(DFS(copy_tickets[i][1], count + 1, len))
                return true;
            visited[i] = false; // 맞는 경로가 아니었을 경우
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    int len = tickets.size();
    copy_tickets = tickets;
    sort(copy_tickets.begin(), copy_tickets.end());
    visited.assign(len,false);  
    DFS("ICN",0, len);
    return answer;
}
