#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1023

int N;
long long ans = 0;
vector<vector<vector<long long> > > dp;
vector<vector<long long> > simple;
void getInput() {
    cin >> N;
    vector<vector<long long> > temp;
    simple.assign(11, vector<long long>());
    temp.assign(10, vector<long long>());
    dp.assign(11, temp);

    for(long long i=0;i<10;i++) {
        dp[0][i].push_back(i);
    }
}

void solution() {
    if(N >= MAX) {
        ans = -1;
        return;
    }

    for(int i=1; i<11; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                if(k > j) {
                    for(int m=0; m < dp[i-1][k].size(); m++) {
                        dp[i][j].push_back(dp[i-1][k][m]  * 10 + j);
                    }
                }
            }
        }
    }

    for(int i=0; i<dp.size(); i++) {
        for(int j=0; j<dp[i].size(); j++) {
            for(int k=0; k<dp[i][j].size(); k++) {
                simple[i].push_back(dp[i][j][k]);
            }
        }
    }

    for(int i=0; i<simple.size(); i++) {
        sort(simple[i].begin(), simple[i].end());
    }

    int i=0;
    for(; i<simple.size(); i++) {
        if(N >= simple[i].size()) {
            N -= simple[i].size();
        }
        else {
            break;
        }
    }

    ans = simple[i][N];
}

int main() {
    getInput();
    solution();
    printf("%lld", ans);
}