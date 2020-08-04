#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos{
    int row;
    int col;
}Pos;

int N,M;
vector<vector<int> > map;
vector<Pos> housePos;

void getInput() {
    cin >> N >> M;
    map.assign(N, vector<int>(N,0));
    housePos.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]) housePos.push_back({i,j});
        }
    }
}

int getDistance(const Pos& service, const Pos& house) {
    return abs(service.row-house.row) + abs(service.col-house.col);
}

void solution(int testnum) {
    int ans=0;

    for(int K=1;K<=N+1;K++) {
        int cost = K*K + (K-1)*(K-1);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int cnt = 0;
                for(int p=0;p<housePos.size();p++){
                    if(getDistance(Pos{i,j}, housePos[p]) <= (K-1)) {
                        cnt += 1;
                    }
                }

                int profit = cnt*M - cost;
                //printf("cost=%d, count=%d, profit=%d\n", cost, cnt, profit);
                if(profit >= 0 && cnt > ans){
                    ans=cnt;
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