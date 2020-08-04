#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string str1, str2;
vector<vector<int> > dp;
int ans = 0;

void getInput() {
    cin >> str1 >> str2;
    dp.assign(str1.size(), vector<int>(str2.size(), 1));
    
}


void solution() {
    for(int i=0; i<str1.size(); i++) {
        if(str1.at(i) == str2.at(0)) {
            break;
        }
        else {
            dp[i][0] = 0;
        }
    }

    for(int i=0; i<str2.size(); i++) {
        if(str1.at(0) == str2.at(i)) {
            break;
        }
        else {
            dp[0][i] = 0;
        }
    }

    for(int i=1; i<str1.size(); i++) {
        for(int j=1; j<str2.size(); j++) {
            if(str1.at(i) == str2.at(j)) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    //printf("dp[%d][%d] = %d\n", 1, 1, dp[1][1]);
    ans = dp[str1.size()-1][str2.size()-1];
}

int main() {
    getInput();
    solution();
    printf("%d", ans);
}