#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int> > numbers(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> numbers[i][j];
        }
    }

    vector<vector<int> > sums(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sums[i][j] = sums[i-1][j] + sums[i][j-1] + numbers[i][j] - sums[i-1][j-1];
        }
    }
    
    for (int i = 0; i < M; i++) {
        int fromX, toX, fromY, toY;
        cin >> fromX >> fromY >> toX >> toY;
        cout << (sums[toX][toY] - sums[toX][fromY-1] - sums[fromX-1][toY] + sums[fromX-1][fromY-1]) << "\n";
    }
    
    return 0;
}