#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int unionParent(int a, int b);
int findParent(int n);

int parent[200001];
int netSize[200001];

void solve() {
    memset(parent, 0, sizeof(parent));
    memset(netSize, 0, sizeof(netSize));

    int N;
    cin >> N;
    int peoples = 0;

    for (int i = 0; i < 200001; i++) {
        parent[i] = i;
        netSize[i] = 1;
    }

    map<string, int> id;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        if (id.count(a) == 0) {
            id[a] = (++peoples);
        }
        if (id.count(b) == 0) {
            id[b] = (++peoples);
        }

        int root = unionParent(id[a], id[b]);
        cout << netSize[root] << "\n";
    }
    
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
    
    return 0;
}

int unionParent(int a, int b) {
    int ap = findParent(a);
    int bp = findParent(b);

    if (ap == bp) return ap;
    int total = netSize[ap] + netSize[bp];
    if (ap < bp) {
        parent[bp] = ap;
        netSize[ap] = total;
        return ap;
    }
    parent[ap] = bp;
    netSize[bp] = total;
    return bp;
}

int findParent(int n) {
    if (n != parent[n]) {
        parent[n] = findParent(parent[n]);
    }
    return parent[n];
}
