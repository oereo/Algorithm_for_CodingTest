#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int N,W,H;
int map[15][12];
int blocklast[12];
int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int ans;

void getInput() {
    cin >> N >> W >> H;
    ans=200;
    memset(map, 0, sizeof(map));
    memset(blocklast, -1, sizeof(blocklast));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>map[i][j];
            if(map[i][j] == 0) {
                blocklast[j] = i;
            }
        }
    }
}

void mapcpy(int src[15][12], int dst[15][12]) {
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            dst[i][j] = src[i][j];
        }
    }
}
void blockcpy(int src[12], int dst[12]) {
    for(int i=0; i<W; i++) {
        dst[i] = src[i];
    }
}

bool isValidPos(int r, int c) {
    return r>=0 && r<H && c>=0 && c<W;
}

void boomseries(int r, int c) {
    int boomsize = map[r][c];
    map[r][c] = 0;
    for(int i=1; i<boomsize; i++) {
        for(int d=0; d<4; d++) {
            int newr = r + dir[d][0]*i;
            int newc = c + dir[d][1]*i;
            if(isValidPos(newr,newc) && map[newr][newc]) {
                boomseries(newr,newc);
            }
        }
    }
}
void updatemap() {
    int buffer[15];
    for(int w=0; w<W; w++) {
        int size = 0;
        memset(buffer,0,sizeof(buffer));
        for(int h=H-1; h>blocklast[w]; h--) {
            if(map[h][w]) {
                buffer[size++] = map[h][w];
                map[h][w] = 0;
            }
        }
        
        for(int i=H-1, j=0; j<size; i--, j++) {
            map[i][w] = buffer[j];
        }
        blocklast[w] = H-1-size;
    }
}

void boom(int pos) {
    int r=blocklast[pos]+1;
    int c=pos;
    int boomsize = map[r][c];
    map[r][c] = 0;
    for(int i=1; i<boomsize; i++) {
        for(int d=0; d<3; d++) {
            int newr = r + dir[d][0]*i;
            int newc = c + dir[d][1]*i;
            if(isValidPos(newr,newc) && map[newr][newc]) {
                boomseries(newr, newc);
            }
        }
    }
    
    updatemap();
}

void dfs(int depth, int pos) {
    int tmap[15][12];
    int tblock[12];
    if(depth==N) {
        mapcpy(map,tmap);
        blockcpy(blocklast, tblock);
        boom(pos);

        int sum=0;
        for(int i=0; i<W; i++) {
            sum += H-1-blocklast[i];
        }
        
        mapcpy(tmap,map);
        blockcpy(tblock, blocklast);
        if(ans>sum) {
            ans=sum;
            return;
        }
    }
    else {
        if(blocklast[pos] == H-1) {
            return;
        }
        if(ans == 0) {
            return;
        }

        mapcpy(map,tmap);
        blockcpy(blocklast, tblock);
        boom(pos);
        for(int p=0; p<W; p++) {
            dfs(depth+1, p);
        }
        mapcpy(tmap,map);
        blockcpy(tblock, blocklast);
    }
}

void solution(int testnum) {
    for(int p=0; p<W; p++) {
        dfs(1, p);
    }
    if(ans==200) ans=0;
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