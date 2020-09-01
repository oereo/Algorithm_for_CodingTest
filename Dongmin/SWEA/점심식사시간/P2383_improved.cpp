#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

typedef struct Pos {
    int row;
    int col;
} Pos;
typedef struct Person {
    Pos pos;
    int stair_distance[2];
} Person;
typedef struct StairUser {
    int num;
    int start_time;
} StairUser;
typedef struct Stair {
    Pos pos;
    queue<int> waitingRow;
    queue<StairUser> usingRow;
} Stair;

int N;
vector<vector<int> > map;
vector<Person> pinfo;
vector<Person> temp;
vector<int> stair_users[2];
Stair stairs[2];

bool operator==(const Pos &a, const Pos &b) {
    return (a.row == b.row) && (a.col == b.col);
}
bool operator!=(const Pos &a, const Pos &b) {
    return !(a==b);
}

void getInput() {
    cin >> N;
    map.assign(N,vector<int>(N,0));
    pinfo.clear();

    int k=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                pinfo.push_back({{i,j},0,0});
            }

            if(map[i][j] > 1) {
                stairs[k++].pos = Pos{i,j}; 
            }
        }
    }

    for(int i=0;i<pinfo.size();i++) {
        for(int j=0; j<2; j++) {
            pinfo[i].stair_distance[j] = abs(stairs[j].pos.row-pinfo[i].pos.row) + abs(stairs[j].pos.col-pinfo[i].pos.col);
            //printf("pinfo[%d]: pos=(%d,%d), stair1_distance=%d, stair2_distance=%d\n", i, pinfo[i].pos.row, pinfo[i].pos.col, pinfo[i].stair1_distance, pinfo[i].stair2_distance);
        }
    }

    temp = pinfo;
}

void dfs(int& min, int idx) {
    if(idx == pinfo.size()) {
        int completedUser = 0;
        int time;
        
        //printf("stair1_users=");
        //for(int i=0;i<stair1_users.size();i++) {
            //printf("%d ", stair1_users[i]);
        //}    
        //printf("\nstair2_users=");
        //for(int j=0;j<stair2_users.size();j++) {
            //printf("%d ", stair2_users[j]);
        //}
        //printf("\n");

        for(time=0; completedUser < pinfo.size(); time++) {
            //printf("[time=%d] completedUser=%d\n", time, completedUser);
            for(int i=0; i<2; i++) {
                while(!stairs[i].usingRow.empty()) {
                    if(time - stairs[i].usingRow.front().start_time == map[stairs[0].pos.row][stairs[0].pos.col]) {
                        //printf("st1.front(): num=%d, start_time=%d\n", st1.front().num, st1.front().start_time);
                        stairs[i].usingRow.pop();
                        completedUser++;
                    } else {
                        break;
                    }
                }
            }
            
            for(int i=0; i<2; i++) {
                while(!stairs[i].waitingRow.empty()) {
                    //printf("waitingRow.front() = %d\n", stairs[i].waitingRow.front());
                    if(stairs[i].usingRow.size() < 3) {
                        int num = stairs[i].waitingRow.front();
                        stairs[i].waitingRow.pop();
                        //printf("waitingRow to usingRow: {%d, %d}\n", num, time);
                        stairs[i].usingRow.push({num, time});
                    } else {
                        break;
                    }
                }
            }
            
            for(int i=0; i<2; i++) {
                for(int j=0; j<stair_users[i].size(); j++) {
                    //printf("pinfo[stair1_users[%d]]: (%d, %d)\n", i, pinfo[stair1_users[i]].pos.row, pinfo[stair1_users[i]].pos.col);
                    if(pinfo[stair_users[i][j]].pos != Pos{-1,-1}) {
                        if(pinfo[stair_users[i][j]].stair_distance[i] - time == 0) {
                            pinfo[stair_users[i][j]].pos = {-1,-1};   // 위층에서 이동하는 것과 관련없음을 나타냄 
                            if(stairs[i].usingRow.size() == 3) {
                                stairs[i].waitingRow.push(stair_users[i][j]);
                            }
                            else {
                                //printf("push %d to st1 at time:%d\n", stair1_users[i], time);
                                stairs[i].usingRow.push({stair_users[i][j], time});   
                            }      
                        }
                    }
                }
            }
        }

        if(time < min) {
            min = time;
        }
        pinfo = temp;
        //printf("final completedUser=%d\n", completedUser);
        return;
    }

    stair_users[0].push_back(idx);
    dfs(min, idx+1);
    stair_users[0].pop_back();

    stair_users[1].push_back(idx);
    dfs(min, idx+1);
    stair_users[1].pop_back();
}


void solution(int testnum) {
    int min = 900000000;
    dfs(min, 0);
    printf("#%d %d\n", testnum, min);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        getInput();
        solution(test_case);
	}
	return 0;
}