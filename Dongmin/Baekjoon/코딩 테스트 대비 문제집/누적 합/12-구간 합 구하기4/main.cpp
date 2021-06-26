#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> numbers(N+1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    
    vector<int> sums(N+1, 0);
    sums[1] = numbers[1];
    for (int i = 2; i <= N; i++) {
        sums[i] = sums[i-1] + numbers[i];
    }
    
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        cout << sums[to] - sums[from-1] << '\n';
    }

    return 0;
}