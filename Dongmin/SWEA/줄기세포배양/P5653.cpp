#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 700

typedef struct Cell{
    int time;
    int vitality;
    int life;
    bool isDead;
} Cell;

int N, M, K;
int ans;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<vector<Cell> > map;
int minr,maxr,minc,maxc;


void getInput() {
    ans=0;
    minr=MAX, maxr=-1, minc=MAX, maxc=-1;
    cin >> N >> M >> K;
    map.assign(MAX, vector<Cell>(MAX, {0,0,0,0}));
    for(int i=(MAX-N)/2, j=0; j<N; i++,j++){
        for(int m=(MAX-M)/2, n=0; n<M; m++,n++){
            cin >> map[i][m].vitality;
            if(map[i][m].vitality){
                minr = min(minr, i);
                maxr = max(maxr, i);
                minc = min(minc, m);
                maxc = max(maxc, m);

                ans++;
                map[i][m].life = -map[i][m].vitality;
                map[i][m].isDead = false;
            }
        }
    }
}

void solution(int testnum) {
    for(int k=1; k<=K; k++) {
        for(int i=minr; i<=maxr; i++){
            for(int j=minc; j<=maxc; j++){
                if(map[i][j].vitality && !map[i][j].isDead) {
                    map[i][j].life += 1;
                    if(map[i][j].life == map[i][j].vitality) {
                        map[i][j].isDead = true;
                        ans--;
                    }
                    else if(!map[i][j].life) {
                        for(int m=0; m<4; m++){
                            int newr = i+dir[m][0], newc = j+dir[m][1];
                            if(!map[newr][newc].isDead && (map[newr][newc].time==k || map[newr][newc].time==0)) {
                                if(!map[newr][newc].life && !map[newr][newc].vitality) {
                                    map[newr][newc].time = k;
                                    map[newr][newc].life = -map[i][j].vitality;
                                    maxr = max(maxr, newr);
                                    maxc = max(maxc, newc);
                                    minr = min(minr, newr);
                                    minc = min(minc, newc);
                                }
                                else if(!map[newr][newc].vitality && map[newr][newc].life) {
                                    if(map[i][j].vitality > abs(map[newr][newc].life)) {
                                        map[newr][newc].life = -map[i][j].vitality;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(!map[i][j].vitality && map[i][j].life && map[i][j].time != k) {
                    ans++;
                    map[i][j].vitality = -map[i][j].life;
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