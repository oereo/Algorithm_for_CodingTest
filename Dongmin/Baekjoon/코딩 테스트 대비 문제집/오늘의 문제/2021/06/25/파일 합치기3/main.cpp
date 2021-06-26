#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for (int i = 0; i < N; i++) {
            long long cost; cin >> cost;
            pq.push(cost);
        }

        long long sum = 0;
        while (!pq.empty()) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();

            sum += (first + second);
            if (pq.empty()) break;
            pq.push(first + second);
        }
        
        cout << sum << '\n';
    }
    

    return 0;
}
