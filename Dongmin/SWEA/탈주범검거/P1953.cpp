#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct tunnelStructure {
    vector<int> dr;
    vector<int> dc;
    vector<int> connected;
} tunst;

typedef struct Pos {
    int row;
    int col;
} Pos;

typedef struct distPos {
    Pos pos;
    int dist;
} distPos;

int N, M;
Pos manhole;
int L;
vector<vector<int> > map;
vector<vector<bool> > visited;
vector<tunst> ts;

void getInput() {
    cin >> N >> M >> manhole.row >> manhole.col >> L;
    map.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }
    
    ts.assign(8, {vector<int>(), vector<int>(), vector<int>()});
    ts[0].dr.push_back(-100);
    ts[0].dc.push_back(-100);
    ts[0].connected.push_back(-100);
    
    ts[1].dr.push_back(0);
    ts[1].dc.push_back(1);
    ts[1].dr.push_back(0);
    ts[1].dc.push_back(-1);
    ts[1].dr.push_back(-1);
    ts[1].dc.push_back(0);
    ts[1].dr.push_back(1);
    ts[1].dc.push_back(0);
    ts[1].connected.push_back(1);    // 1:좌, 2:상, 3:우, 4:하
    ts[1].connected.push_back(2);
    ts[1].connected.push_back(3);
    ts[1].connected.push_back(4);

    ts[2].dr.push_back(-1);
    ts[2].dr.push_back(1);
    ts[2].dc.push_back(0);
    ts[2].dc.push_back(0);
    ts[2].connected.push_back(2);
    ts[2].connected.push_back(4);

    ts[3].dr.push_back(0);
    ts[3].dr.push_back(0);
    ts[3].dc.push_back(-1);
    ts[3].dc.push_back(1);
    ts[3].connected.push_back(1);
    ts[3].connected.push_back(3);

    ts[4].dr.push_back(-1);
    ts[4].dr.push_back(0);
    ts[4].dc.push_back(0);
    ts[4].dc.push_back(1);
    ts[4].connected.push_back(2);
    ts[4].connected.push_back(3);

    ts[5].dr.push_back(1);
    ts[5].dr.push_back(0);
    ts[5].dc.push_back(0);
    ts[5].dc.push_back(1);
    ts[5].connected.push_back(3);
    ts[5].connected.push_back(4);
    
    ts[6].dr.push_back(0);
    ts[6].dr.push_back(1);
    ts[6].dc.push_back(-1);
    ts[6].dc.push_back(0);
    ts[6].connected.push_back(1);
    ts[6].connected.push_back(4);

    ts[7].dr.push_back(-1);
    ts[7].dr.push_back(0);
    ts[7].dc.push_back(0);
    ts[7].dc.push_back(-1);
    ts[7].connected.push_back(1);
    ts[7].connected.push_back(2);
    // for(tunst el:ts) {
    //     printf("\ndr[i]=");
    //     for(int r:el.dr) {
    //         printf("%d ", r);
    //     }
    //     printf("\ndc[i]=");
    //     for(int c:el.dc) {
    //         printf("%d ", c);
    //     }
    //     printf("\nconnected[i]=");
    //     for(int con:el.connected) {
    //         printf("%d ", con);
    //     }
    //            
    // }
}

bool isValidPos(Pos& pos) {
    return (pos.row >= 0 && pos.row < N && pos.col >=0 && pos.col < M);
}

void solution(int testnum) {
    int ans = 0;
    queue<distPos> q;
    q.push({manhole, 0});
    visited[manhole.row][manhole.col] = true;

    while(!q.empty()) {
        distPos here = q.front();
        //printf("here distPos: (%d, %d), %d\n", here.pos.row, here.pos.col, here.dist);
        q.pop();
        if(here.dist > L-1) {
            break;
        }
        ans++;
        tunst nowStructure = ts[map[here.pos.row][here.pos.col]];

        for(int i=0; i < nowStructure.dr.size(); i++) {
            //printf("nowStructure: dr=%d, dc=%d, connected=%d\n", nowStructure.dr[i], nowStructure.dc[i], nowStructure.connected[i]);
            Pos there = {here.pos.row + nowStructure.dr[i], here.pos.col + nowStructure.dc[i]};
            if(!isValidPos(there)) {
                continue;
            }
            
            tunst nextStructure = ts[map[there.row][there.col]];

            if (map[there.row][there.col]) {
                //printf("there pass:(%d, %d)\n", there.row, there.col);
                bool canGo = false;
                if(nowStructure.dr[i] == 0 && nowStructure.dc[i] == 1) {
                    // 오른쪽
                    for(int j=0;j<nextStructure.connected.size(); j++) {
                        if(nextStructure.connected[j] == 1) {
                            canGo = true;
                        }
                    }
                } else if(nowStructure.dr[i] == 1 && nowStructure.dc[i] == 0) {
                    // 아래쪽
                    for(int j=0;j<nextStructure.connected.size(); j++) {
                        if(nextStructure.connected[j] == 2) {
                            canGo = true;
                        }
                    }
                } else if(nowStructure.dr[i] == 0 && nowStructure.dc[i] == -1) {
                    // 왼쪽
                    for(int j=0;j<nextStructure.connected.size(); j++) {
                        if(nextStructure.connected[j] == 3) {
                            canGo = true;
                        }
                    }
                } else {
                    // 위쪽
                    for(int j=0;j<nextStructure.connected.size(); j++) {
                        if(nextStructure.connected[j] == 4) {
                            canGo = true;
                        }
                    }
                }

                if(!visited[there.row][there.col] && canGo) {
                    q.push({there, here.dist+1});
                    visited[there.row][there.col] = true;
                }
            }
        }
    }

    printf("#%d %d\n", testnum, ans);
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