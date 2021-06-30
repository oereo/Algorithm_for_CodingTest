#include <bits/stdc++.h>
using namespace std;

int check[5003];
int accumulated[5003];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K, Q, M;
    cin >> N >> K >> Q >> M;
    memset(check, 0, sizeof(check));
    memset(accumulated, 0, sizeof(accumulated));

    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        check[k] = -1;
    }

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (check[q] == -1) continue;
        for (int j = q; j < 5003; j += q) {
            if (check[j] == -1) continue;
            check[j] = 1;
        }
    }

    for (int i = 3; i < N + 3; i++) {
        accumulated[i] = accumulated[i-1] + (check[i] != 1);
    }
    

    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        cout << accumulated[E] - accumulated[S-1] << "\n";
    }
    
    return 0;
}
