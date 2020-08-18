#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,ans;
int synergy[16][16];
const int THRES[7] = {6,20,70,252,924,3432,12870};

void getInput() {
    ans = 40001;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> synergy[i][j];
        }
    }
}

void dfs(int& num, int idx, vector<int>& a, vector<int>& b) {
    if(idx == N) {
        if(num>=THRES[(N-4)/2]) return;
        int suma=0, sumb=0;
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                suma += synergy[a[i]][a[j]];
                suma += synergy[a[j]][a[i]];
            }
        }
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                sumb += synergy[b[i]][b[j]];
                sumb += synergy[b[j]][b[i]];
            }
        }

        if(ans>abs(suma-sumb)){
            ans=abs(suma-sumb);
        }
        num += 1;
    }
    else {
        a.push_back(idx);
        if(a.size()<=N/2){
            dfs(num,idx+1,a,b);
        }
        a.pop_back();
        b.push_back(idx);
        if(b.size()<=N/2){
            dfs(num,idx+1,a,b);
        }
        b.pop_back();
    }
}

void solution(int testnum) {
    vector<int> a,b;
    int num=0;
    dfs(num,0,a,b);
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