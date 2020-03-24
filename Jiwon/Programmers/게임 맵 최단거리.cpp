/*
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 따라서, 
각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

지금부터 당신은 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 다음은 5 x 5 크기의 맵에, 
당신의 캐릭터가 (행: 1, 열: 1) 위치에 있고, 상대 팀 진영은 (행: 5, 열: 5) 위치에 있는 경우의 예시입니다.

게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 
칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

예:
maps	                                                        answer
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]	11
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	-1
*/

#include <vector>
#include <queue>
using namespace std;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int dist[101][101];

int solution(vector<vector<int>> maps){
	int answer = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    for(int i = 0; i< maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){            
            dist[i][j] = 0;
        }
    }

    dist[0][0] = 1;
    visited[0][0] = true;
    q.push({0,0});    
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (0 <= nx && nx < maps.size() && 0 <= ny && ny < maps[0].size()){
                if(visited[nx][ny] == false && maps[nx][ny] == 1){
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx,ny});
                    if(nx == maps.size() - 1 && ny == maps[0].size() - 1){
                        answer = dist[nx][ny];
                    }
                }
            }
        }
    }

    if(answer == 0) answer = -1;

	return answer;

}