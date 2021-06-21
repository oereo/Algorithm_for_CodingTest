#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;

int N,M,K;
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    cin >> N >> M;
    vector<vector<int> > map(N+1, vector<int>(M+1, 0));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> map[i][j];
            dp[i][j] = map[i][j] + (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
        }
    }

    cin >> K;
    for (int i=0; i<K; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << "\n";
    }

    return 0;
}