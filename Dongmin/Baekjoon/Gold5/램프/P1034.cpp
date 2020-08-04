#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Pos {
    int row;
    int col;
} Pos;
int N, M, K;
vector<string> lamps;
vector<int> offnum;
int ans=0;

void getInput() {
    cin >> N >> M;
    string temp;
    offnum.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin >> temp;
        lamps.push_back(temp);
        for(int j=0; j<M; j++) {
            if(temp[j] - '0' == 0) {
                offnum[i] += 1;
            }
        }
    }
    cin >> K;
}


void solution() {
    for(int i=0; i<N; i++) {
        int cnt = 0;
        if(offnum[i] <= K && offnum[i]%2 == K%2) {
            for(int j=0; j<N; j++) {
                if(lamps[i] == lamps[j]) {
                    cnt++;
                }
            }
        }
        ans = cnt > ans ? cnt:ans;
    }
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}