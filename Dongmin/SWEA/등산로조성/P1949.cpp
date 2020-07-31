#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row,col;
}Pos;
Pos operator+(const Pos &a, const Pos &b) {
    return {a.row + b.row, a.col + b.col};
}
bool operator==(const Pos &a, const Pos &b) {
    return (a.row == b.row) && (a.col == b.col);
}
bool operator!=(const Pos &a, const Pos &b) {
    return !(a==b);
}

int N,K;
vector<vector<int> > map;
vector<Pos> peekPos;
int dr[4]={0,-1,1,0};
int dc[4]={1,0,0,-1};

void getInput() {
    int max =-1;
    cin>>N>>K;
    map.assign(N, vector<int>(N,0));
    peekPos.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]>max) max=map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == max) {
                peekPos.push_back({i,j});
            }
        }
    }
}
bool isValidPos(const Pos& pos){
    return pos.row>=0 && pos.row<N && pos.col>=0 && pos.col<N;
}

void dfs(Pos pos, int& maxlen, int len) {
    Pos next;
    for(int i=0; i<4; i++){
        next = pos + Pos{dr[i], dc[i]};
        if(isValidPos(next) && map[pos.row][pos.col] > map[next.row][next.col]) {
            dfs(next, maxlen, len+1);
        }
    }

    if(len>maxlen){
        maxlen=len;        
    }
}

void solution(int testnum) {
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=1;k<=K;k++) {
                map[i][j] -= k;
                for(int p=0;p<peekPos.size();p++){
                    if(peekPos[p]!=Pos{i,j})
                        dfs(peekPos[p], ans, 1);
                }
                map[i][j] += k;
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