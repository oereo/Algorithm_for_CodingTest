#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
typedef struct Pos {
    int row;
    int col;
} Pos;
typedef struct distPos {
    Pos pos;
    int distance;
} DistPos;
typedef struct PassengerInfo {
    int num;
    int dist;
} PassengerInfo;

int N, M;
int fuel;
vector<vector<int> > grid;
vector<vector<bool> > visited;
Pos taxiPos;
vector<Pos> pStartPos;
vector<Pos> pEndPos;
list<int> remainedPassengers;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};


void getInput() {
    cin >> N >> M >> fuel;
    grid.assign(N+2, vector<int>(N+2, -1));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> taxiPos.row >> taxiPos.col;
    pStartPos.assign(M, Pos{-1,-1});
    pEndPos.assign(M, Pos{-1,-1});
    for(int i=0; i<M; i++) {
        cin >> pStartPos[i].row >> pStartPos[i].col >> pEndPos[i].row >> pEndPos[i].col;
        remainedPassengers.push_back(i);
    }
    visited.assign(N+2, vector<bool>(N+2, false));
}
void initVisited() {
    visited.assign(N+2, vector<bool>(N+2, false));
}
void visitCheck(Pos &pos) {
    visited[pos.row][pos.col] = true;
}
int discoverPassenger(Pos pos) {
    for(auto passenger:remainedPassengers) {
        if(pStartPos[passenger].row == pos.row && pStartPos[passenger].col == pos.col) {
            int ret = passenger;
            return ret;
        }
    }
    return -1;
}

PassengerInfo pickNextPassenger() {
    int closestPassengerDist = 1000*N;
    PassengerInfo closestPassenger = PassengerInfo{-1, -1};
    int passRow = N+1, passCol = N+1;
    int startPosCheck = discoverPassenger(taxiPos);
    if(startPosCheck > 0) {
        return PassengerInfo{startPosCheck, 0};
    }

   queue<DistPos> q;
    q.push(DistPos{taxiPos,0});
    visitCheck(taxiPos);
    while(!q.empty()) {
        DistPos here = q.front();
        q.pop();
        if(here.distance < closestPassengerDist) {
            for(int i = 0; i < 4; i++) {
                Pos next = Pos {here.pos.row + dr[i], here.pos.col + dc[i]};
                if(!visited[next.row][next.col] && grid[next.row][next.col] == 0) {
                    int passengerNum = discoverPassenger(next);
                    if(passengerNum == -1) {
                        q.push(DistPos{next, here.distance+1});
                        visitCheck(next);
                    }
                    else {
                        // 승객 스케줄링 정책
                        if (closestPassengerDist >= here.distance+1) {
                            closestPassengerDist = here.distance + 1;
                            if(pStartPos[passengerNum].row < passRow) {
                                closestPassenger = PassengerInfo{passengerNum, here.distance+1};
                                passRow = pStartPos[passengerNum].row;
                                passCol = pStartPos[passengerNum].col;
                            }
                            else if(pStartPos[passengerNum].row == passRow) {
                                if(pStartPos[passengerNum].col < passCol) {
                                    closestPassenger = PassengerInfo{passengerNum, here.distance+1};
                                    passRow = pStartPos[passengerNum].row;
                                    passCol = pStartPos[passengerNum].col;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return closestPassenger;
}

bool isAvailableFuelSize(PassengerInfo info) {
    if(info.dist > fuel) return false;
    return true;
}

void moveToPassengerPos(PassengerInfo info) {
    fuel -= info.dist;
    taxiPos = pStartPos[info.num];
}

int moveToDestination(PassengerInfo info) {
    queue<DistPos> q;
    q.push(DistPos{taxiPos,0});
    visitCheck(taxiPos);
    while(!q.empty()) {
        DistPos here = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            Pos next = Pos {here.pos.row + dr[i], here.pos.col + dc[i]};
            if(!visited[next.row][next.col] && grid[next.row][next.col] == 0) {
                if(pEndPos[info.num].row == next.row && pEndPos[info.num].col == next.col){    
                    taxiPos = pEndPos[info.num];
                    fuel += (here.distance+1);
                    //cout << "destination pos:[" << taxiPos.row << "," << taxiPos.col << "], remained fuel: " << fuel << ", distance: " << 
                    // here.distance+1 << "\n";
                    return 1;
                }

                if(fuel > here.distance+1) {
                    q.push(DistPos{next, here.distance+1});
                    visitCheck(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    getInput();
    for(int i = 0; i < M; i++) {
        // 태울 승객 선택
        PassengerInfo nextPassenger = pickNextPassenger();
        if(nextPassenger.num == -1) {
            cout << "-1";
            return 0;
        }

        //cout << "next passenger:[" << pStartPos[nextPassenger.num].row << "," << pStartPos[nextPassenger.num].col << "], distance: " << nextPassenger.dist << "\n";
        remainedPassengers.remove(nextPassenger.num);
        initVisited();
        // 가능 여부 확인 -> 불가능하면 -1 출력하고 종료
        if(!isAvailableFuelSize(nextPassenger)) {
            cout << "-1";
            return 0;
        }
        // 최단거리로 이동
        moveToPassengerPos(nextPassenger);
        // 목적지에 최단거리로 이동
        int success = moveToDestination(nextPassenger);
        if (success < 0) {
            cout << "-1";
            return 0;
        }
        initVisited();
    }
    cout << fuel;
}
