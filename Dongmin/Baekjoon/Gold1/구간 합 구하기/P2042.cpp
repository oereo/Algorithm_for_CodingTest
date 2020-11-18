#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int N, M, K;
vector<long long> org;
vector<long long> stree;

long long initTree(int start, int end, int node) {
    if(start == end) return stree[node] = org[start];
    else {
        int mid = (start + end) / 2;
        return stree[node] = initTree(start, mid, node*2) + initTree(mid+1, end, node*2 + 1);
    }
}

void getInput() {
    cin >> N >> M >> K;

    stree.assign(4*N, 0);
    org.assign(N, 0);
    for(int i=0; i<N; i++) {
        cin >> org[i];
    }
    initTree(0, N-1, 1);
}

long long getPrefixSum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return stree[node];
    else {
        int mid = (start + end) / 2;
        return getPrefixSum(start, mid, node*2, left, right) + getPrefixSum(mid+1, end, node*2 + 1, left, right);
    }
}

void updateTree(int start, int end, int node, int updated_index, long long diff) {
    if(updated_index < start || updated_index > end) {
        return;
    }
    else {
        stree[node] += diff;
        if(start == end) return;
        int mid = (start + end) / 2;
        updateTree(start, mid, node*2, updated_index, diff);
        updateTree(mid+1, end, node*2 + 1, updated_index, diff);
    }
}

void solution() {
    for(int i=0; i<M+K; i++) {
        long long type, a, b;
        cin >> type >> a >> b;
        if(type == 1) {
            long long diff = b - org[a-1];
            org[a-1] = b;
            updateTree(0, N-1, 1, a-1, diff);
        }
        else {
            cout << getPrefixSum(0, N-1, 1, a-1, b-1) << endl;
        }
    }
}

int main() {
    getInput();
    solution();
}