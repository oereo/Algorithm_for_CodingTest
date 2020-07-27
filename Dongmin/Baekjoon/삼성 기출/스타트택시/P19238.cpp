#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row;
    int col;
} Pos;
typedef struct Passenger {
    Pos start;
    Pos dest;
} Passenger;
typedef struct DistPos {
    int dist;
    Pos pos;
} DistPos;

vector<vector<int> > map;
vector<vector<bool> > visited;
Pos taxiStart;
vector<Passenger> passengers;
int N, M, fuel;
Pos dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool operator==(const Pos& a, const Pos& b) {
    return (a.row == b.row && a.col == b.col);
}
bool operator!=(const Pos& a, const Pos& b) {
    return !(a==b);
}
Pos operator+(const Pos& a, const Pos& b) {
    return Pos{a.row + b.row, a.col + b.col};
}

void getInput() {
    cin >> N >> M >> fuel;
    map.assign(N+2, vector<int>(N+2, -1));
    visited.assign(N+2, vector<bool>(N+2, false));
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> map[i][j];
        }
    }

    cin >> taxiStart.row >> taxiStart.col;
    passengers.assign(M, Passenger({{-1,-1},{-1,-1}}));
    for(int i=0;i<M;i++) {
        cin >> passengers[i].start.row >> passengers[i].start.col >> passengers[i].dest.row >> passengers[i].dest.col;
    }
}

int discoverPassenger(Pos pos) {
    int ret = -1;
    for(int i=0;i<passengers.size(); i++) {
        if(passengers[i].start == pos && passengers[i].start != Pos{-1,-1}) {
            ret = i;
        }
    }
    return ret;
}

void visitCheck(Pos& pos) {
    visited[pos.row][pos.col] = true;
}

int pickNextPassenger() {
    int next = -1;
    int limitDist = 900000000;
    queue<DistPos> q;
    q.push({0, taxiStart});
    visitCheck(taxiStart);

    while(!q.empty()) {
        DistPos here = q.front();
        q.pop();
        if(here.dist > limitDist) {
            break;
        }

        int temp = discoverPassenger(here.pos);
        if(temp > -1) {
            limitDist = here.dist;
            if(next == -1) {
                next = temp;
            }
            else {
                if(passengers[next].start.row > passengers[temp].start.row) {
                    next = temp;
                }
                else if(passengers[next].start.row == passengers[temp].start.row) {
                    if(passengers[next].start.col > passengers[temp].start.col) {
                        next = temp;
                    }
                }
            }
        }
        
        for(int i=0;i<4;i++) {
            Pos there = here.pos + dir[i];
            if(!visited[there.row][there.col] && here.dist + 1 <= limitDist && map[there.row][there.col] == 0) {
                q.push({here.dist + 1, there});
                visitCheck(there);
            }
        }
    }

    if(limitDist >= fuel) {
        next = -1;
    }
    fuel -= limitDist;
    return next;
}

int goDestination(int passNum) {
    int distance = -1;
    queue<DistPos> q;
    q.push({0, taxiStart});
    visitCheck(taxiStart);

    while(!q.empty()) {
        DistPos here = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            Pos there = here.pos + dir[i];
            if(!visited[there.row][there.col] && map[there.row][there.col] == 0) {
                q.push({here.dist + 1, there});
                visitCheck(there);
                if(passengers[passNum].dest == there) {
                    distance = here.dist + 1;
                    break;
                } 
            }
        }
    }

    if(distance > fuel) {
        distance = -1;
    }
    else {
        fuel -= distance;
    }
    return distance;
}

void solution() {
    for(int i=0;i<M;i++) { 
        int nextPassenger = pickNextPassenger();
        if(nextPassenger == -1) {
            fuel = -1;
            return;
        }
        //printf("go to #%d passenger, remained fuel: %d\n", nextPassenger, fuel);
        taxiStart = passengers[nextPassenger].start;
        visited.assign(N+2, vector<bool>(N+2, false));


        int distance = goDestination(nextPassenger);
        if(distance == -1) {
            fuel = -1;
            return;
        }

        taxiStart = passengers[nextPassenger].dest;
        fuel += (2*distance);
        //printf("go to #%d passenger dest, remained fuel: %d\n", nextPassenger, fuel);
        passengers[nextPassenger].start = Pos{-1,-1};
        visited.assign(N+2, vector<bool>(N+2, false));
    }
}

int main() {
    getInput();
    solution();
    printf("%d", fuel);
}