#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row;
    int col;
}Pos;
typedef struct Charger {
    Pos pos;
    int conv;
    int perf;
} Charger;
typedef struct User {
    Pos pos;
    vector<int> trace;
} User;

Pos operator+(const Pos &a, const Pos &b) {
    return {a.row + b.row, a.col + b.col};
}
bool operator==(const Pos &a, const Pos &b) {
    return (a.row == b.row) && (a.col == b.col);
}
bool operator!=(const Pos &a, const Pos &b) {
    return !(a==b);
}

int M, A;
int dr[5]={0,-1,0,1,0};
int dc[5]={0,0,1,0,-1};
vector<User> users;
vector<Charger> chargers;

void getInput() {
    cin >> M >> A;
    users.assign(2, User{{0,0}, vector<int>(M,0)});
    users[0].pos = {1,1};
    users[1].pos = {10,10};
    
    for(int i=0;i<2;i++){
        for(int j=0;j<M;j++){
            cin >> users[i].trace[j];
        }
    }

    chargers.assign(A, Charger{{0,0},0,0});
    for(int i=0;i<A;i++){
        cin >> chargers[i].pos.col >> chargers[i].pos.row >> chargers[i].conv >> chargers[i].perf;
    }
    
}

int getDistance(const Pos& pos, const Pos& charger) {
    return abs(pos.row-charger.row) + abs(pos.col-charger.col);
}

void solution(int testnum) {
    int ans=0;
    // t=0에서의 충전량 설정
    for(int i=0;i<2;i++){
        int max = 0;
        for(int j=0;j<A;j++){
            int charged = chargers[j].perf * (getDistance(users[i].pos, chargers[j].pos) <= chargers[j].conv);
            if(charged > max) {
                max = charged;
            }
        }
        ans += max;
    }

    // t>=1에서의 충전량
    for(int m=0; m<M; m++) {
        for(int i=0;i<2;i++){
            users[i].pos = users[i].pos + Pos{dr[users[i].trace[m]], dc[users[i].trace[m]]};
        }

        vector<int> usedCharger[2];
        usedCharger[0].assign(A, false);
        usedCharger[1].assign(A, false);
        for(int i=0; i<A; i++) {
            usedCharger[0][i] = getDistance(users[0].pos, chargers[i].pos) <= chargers[i].conv;
            usedCharger[1][i] = getDistance(users[1].pos, chargers[i].pos) <= chargers[i].conv;
        }

        int max = 0;
        int sum=0;
        for(int i=0; i<A; i++) {
            for(int j=0; j<A; j++) {
                if(i==j && usedCharger[0][i] && usedCharger[1][j]) {
                    sum = chargers[i].perf;
                }
                else {
                    sum = usedCharger[0][i]*chargers[i].perf + usedCharger[1][j]*chargers[j].perf;
                }

                if(sum>max) {
                    max = sum;
                }
            }
        }
        ans += max;
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