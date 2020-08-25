#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Atom {
    int x,y;
    int dir;
    int energy;
    bool isDisappeared;
} Atom;
typedef struct Acc {
    float time;
    float x,y;
    int a,b;
} Acc;
struct cmp{
    bool operator()(Acc t, Acc u){
        return t.time > u.time;
    }
};

int N, ans;
priority_queue<Acc, vector<Acc>, cmp> pq;
Atom atoms[1000];

int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

void getInput() {
    ans=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> atoms[i].x >> atoms[i].y >> atoms[i].dir >> atoms[i].energy;
        atoms[i].isDisappeared = false;
    }
}

void crash(const Atom& a, int ai, const Atom& b, int bi) {
    if(abs(a.dir - b.dir) == 1 && !(a.dir==1 && b.dir==2) && !(a.dir==2 && b.dir==1)) {
        if(a.dir <= 1) {
            if(a.x == b.x) {
                if(a.dir==0) {
                    if(a.y < b.y) {
                        pq.push({abs(a.y-b.y)/2.0, a.x, (a.y+b.y)/2.0, ai, bi});
                    }
                }
                else {
                    if(a.y > b.y) {
                        pq.push({abs(a.y-b.y)/2.0, a.x, (a.y+b.y)/2.0, ai, bi});
                    }
                }
            }
        }
        else {
            if(a.y == b.y) {
                if(a.dir==2 && a.x > b.x) {
                    pq.push({abs(a.x-b.x)/2.0, (a.x+b.x)/2.0, a.y, ai, bi});
                }
                else if(a.dir==3 && a.x < b.x) {
                    pq.push({abs(a.x-b.x)/2.0, (a.x+b.x)/2.0, a.y, ai, bi});
                }
            }
        }   
    }
    else {
        if(abs(a.x-b.x) == abs(a.y-b.y)) {
            float accx = (dir[a.dir][0]==0) * a.x + (dir[b.dir][0]==0) * b.x;
            float accy = (dir[a.dir][1]==0) * a.y + (dir[b.dir][1]==0) * b.y;
            int startx = (dir[a.dir][0]!=0) * a.x + (dir[b.dir][0]!=0) * b.x;
            int starty = (dir[a.dir][1]!=0) * a.y + (dir[b.dir][1]!=0) * b.y;
            int dirx = dir[a.dir][0] + dir[b.dir][0];
            int diry = dir[a.dir][1] + dir[b.dir][1];
            if(startx + abs(a.x-b.x)*dirx == accx && starty + abs(a.x-b.x)*diry == accy){
                pq.push({abs(a.x-b.x), accx, accy, ai, bi});
            }
        }
    }
}

void solution(int testnum) {
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            crash(atoms[i], i, atoms[j], j);
        }
    }

    vector<Acc> buf;
    float time = 0.0;
    while(!pq.empty()) {
        Acc acc = pq.top();
        pq.pop();

        if(acc.time == time) {
            if(!atoms[acc.a].isDisappeared && !atoms[acc.b].isDisappeared) {
                buf.push_back(acc);
            }
        }
        else {
            time = acc.time;
            for(int i=0; i<buf.size(); i++) {
                Acc tmp = buf[i];
                if(!atoms[tmp.a].isDisappeared) {
                    ans += atoms[tmp.a].energy;
                    atoms[tmp.a].isDisappeared = true;
                }

                if(!atoms[tmp.b].isDisappeared) {
                    ans += atoms[tmp.b].energy;
                    atoms[tmp.b].isDisappeared = true;
                }
            }
            buf.clear();
            if(!atoms[acc.a].isDisappeared && !atoms[acc.b].isDisappeared) {
                buf.push_back(acc);
            }
        }
    }

    for(int i=0; i<buf.size(); i++) {
        Acc tmp = buf[i];
        if(!atoms[tmp.a].isDisappeared) {
            ans += atoms[tmp.a].energy;
            atoms[tmp.a].isDisappeared = true;
        }
        if(!atoms[tmp.b].isDisappeared) {
            ans += atoms[tmp.b].energy;
            atoms[tmp.b].isDisappeared = true;
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