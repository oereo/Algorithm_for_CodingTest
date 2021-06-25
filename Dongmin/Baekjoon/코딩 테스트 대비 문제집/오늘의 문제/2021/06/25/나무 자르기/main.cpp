#include <bits/stdc++.h>
using namespace std;
struct Tree {
    int init, growth;
};

bool operator<(const Tree u, const Tree v) {
    return u.growth < v.growth;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Tree> trees(N, {0,0});

    for (int i = 0; i < N; i++) {
        cin >> trees[i].init;
    }
    for (int i = 0; i < N; i++) {
        cin >> trees[i].growth;
    }
    
    long long sum = 0;
    sort(trees.begin(), trees.end());
    for (int i = 0; i < N; i++) {
        sum += (long long) (trees[i].init + i * trees[i].growth);
    }
    
    cout << sum << '\n';
    return 0;
}