#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void unionParent(int* parent, int a, int b);
int findParent(int* parent, int n);
void clean(int* parent, int* friendCost);

int main() {
    int N, M, k;
    cin >> N >> M >> k;

    int* friendCost = new int[N+1];
    int* parent = new int[N+1];
    
    friendCost[0] = 0;
    parent[0] = 0;
    for (int i = 1; i < N+1; i++) {
        cin >> friendCost[i];
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        unionParent(parent, v, w);
    }

    // 부모 노드 동기화 되지 않은 것들 수정
    for (int i = 0; i < N+1; i++) {
        findParent(parent, i);
    }

    map<int, int> types;
    for (int i = 1; i < N+1; i++) {
        int key = parent[i];
        if (types.count(key) == 0) {
            types[key] = friendCost[key];
            continue;
        }
        types[key] = min(friendCost[i], types[key]);
    }
    
    int sum = 0;
    for (auto t : types) {
        sum += t.second;
        if (sum > k) {
            clean(parent, friendCost);
            cout << "Oh no" << endl;
            return 0;
        } 
    }

    cout << sum << endl;
    clean(parent, friendCost);
    return 0;
}

void unionParent(int* parent, int a, int b) {
    int ap = findParent(parent, a);
    int bp = findParent(parent, b);

    if (ap < bp) {
        parent[bp] = ap;
    } else {
        parent[ap] = bp;
    }
}

int findParent(int* parent, int n) {
    if (n != parent[n]) {
        parent[n] = findParent(parent, parent[n]);
    }
    return parent[n];
}

void clean(int* parent, int* friendCost) {
    delete[] parent;
    delete[] friendCost;
}