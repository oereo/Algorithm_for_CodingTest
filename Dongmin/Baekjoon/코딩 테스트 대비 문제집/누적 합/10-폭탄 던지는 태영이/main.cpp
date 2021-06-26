#include <bits/stdc++.h>
using namespace std;

long long calculateSum(vector<vector<long long> > &sums, int N, int r, int c) {
    if (r < 0 || c < 0) return 0;
    return sums[r][c];
}

long long calculateBomb(vector<vector<long long> > &bomb, int N, int r, int c) {
    if (r < 0 || c < 0) return 0;
    return bomb[r][c];    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<long long> > bombs(N, vector<long long>(N, 0));
    vector<vector<long long> > sums(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long h;
            cin >> h;
            sums[i][j] = -h;
        }
    }

    for (int i = M/2; i < N-M/2; i++) {
        for (int j = M/2; j < N-M/2; j++) {
            bombs[i][j] = sums[i-M/2][j-M/2] + calculateSum(sums, N, i-M/2-1, j-M/2-1) - calculateSum(sums, N, i-M/2-1, j-M/2)
                        -calculateSum(sums, N, i-M/2, j-M/2-1) - calculateBomb(bombs, N, i-M, j-M) + calculateBomb(bombs, N, i-M, j) + calculateBomb(bombs, N, i, j-M);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bombs[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}