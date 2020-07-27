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
typedef struct Pinfo {
    Pos pos;
    int stair1_distance;
    int stair2_distance;
} Pinfo;
typedef struct StairUser {
    int num;
    int start_time;
} StairUser;

int N;
vector<vector<int> > map;
vector<Pinfo> pinfo;
vector<Pinfo> temp;
vector<int> stair1_users;
vector<int> stair2_users;
Pos stairs[2];

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
                stairs[k++] = {i,j}; 
            }
        }
    }

    for(int i=0;i<pinfo.size();i++) {
        pinfo[i].stair1_distance = abs(stairs[0].row-pinfo[i].pos.row) + abs(stairs[0].col-pinfo[i].pos.col);
        pinfo[i].stair2_distance = abs(stairs[1].row-pinfo[i].pos.row) + abs(stairs[1].col-pinfo[i].pos.col);
        //printf("pinfo[%d]: pos=(%d,%d), stair1_distance=%d, stair2_distance=%d\n", i, pinfo[i].pos.row, pinfo[i].pos.col, pinfo[i].stair1_distance, pinfo[i].stair2_distance);
    }

    temp = pinfo;
}

void dfs(int& min, int idx) {
    if(idx == pinfo.size()) {
        queue<int> waitingRow1;
        queue<int> waitingRow2;
        queue<StairUser> st1;
        queue<StairUser> st2;
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

            while(!st1.empty()) {
                if(time - st1.front().start_time == map[stairs[0].row][stairs[0].col]) {
                    //printf("st1.front(): num=%d, start_time=%d\n", st1.front().num, st1.front().start_time);
                    st1.pop();
                    completedUser++;
                } else {
                    break;
                }
            }

            while(!st2.empty()) {
                if(time - st2.front().start_time == map[stairs[1].row][stairs[1].col]) {
                    //printf("st2.front(): num=%d, start_time=%d\n", st2.front().num, st2.front().start_time);
                    st2.pop();
                    completedUser++;
                } else {
                    break;
                }
            }

            while(!waitingRow1.empty()) {
                //printf("waitingRow1.front() = %d\n", waitingRow1.front());
                if(st1.size() < 3) {
                    int num = waitingRow1.front();
                    waitingRow1.pop();
                    //printf("waitingRow1 to st1: {%d, %d}\n", num, time);
                    st1.push({num, time});
                } else {
                    break;
                }
            }

            while(!waitingRow2.empty()) {
                //printf("waitingRow2.front() = %d\n", waitingRow2.front());
                if(st2.size() < 3) {
                    int num = waitingRow2.front();
                    waitingRow2.pop();
                    st2.push({num, time});
                } else {
                    break;
                }
            }

            for(int i=0; i<stair1_users.size(); i++) {
                //printf("pinfo[stair1_users[%d]]: (%d, %d)\n", i, pinfo[stair1_users[i]].pos.row, pinfo[stair1_users[i]].pos.col);
                if(pinfo[stair1_users[i]].pos != Pos{-1,-1}) {
                    if(pinfo[stair1_users[i]].stair1_distance - time == 0) {
                        pinfo[stair1_users[i]].pos = {-1,-1};   // 위층에서 이동하는 것과 관련없음을 나타냄 
                        if(st1.size() == 3) {
                            waitingRow1.push(stair1_users[i]);
                        }
                        else {
                            //printf("push %d to st1 at time:%d\n", stair1_users[i], time);
                            st1.push({stair1_users[i], time});   
                        }      
                    }
                }
            }

            for(int j=0; j<stair2_users.size(); j++) {
                //printf("pinfo[stair2_users[%d]]: (%d, %d)\n", j, pinfo[stair2_users[j]].pos.row, pinfo[stair2_users[j]].pos.col);
                if(pinfo[stair2_users[j]].pos != Pos{-1,-1}) {
                    if(pinfo[stair2_users[j]].stair2_distance - time == 0) {
                        pinfo[stair2_users[j]].pos = {-1,-1};   // 위층에서 이동하는 것과 관련없음을 나타냄 
                        if(st2.size() == 3) {
                            waitingRow2.push(stair2_users[j]);
                        }
                        else {
                            //printf("push %d to st2 at time:%d\n", stair2_users[j], time);
                            st2.push({stair2_users[j], time});   
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

    stair1_users.push_back(idx);
    dfs(min, idx+1);
    stair1_users.pop_back();

    stair2_users.push_back(idx);
    dfs(min, idx+1);
    stair2_users.pop_back();
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