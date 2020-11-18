#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<limits.h>
using namespace std;
typedef struct Node {
    int max, min;
} Node;

int N, M;
vector<int> org;
vector<Node> stree;

Node initTree(int start, int end, int node) {
    if(start == end) {
        stree[node].max = org[start];
        stree[node].min = org[start];
        return {org[start], org[start]};
    }
    else {
        int mid = (start + end) / 2;
        Node left = initTree(start, mid, node*2);
        Node right = initTree(mid+1, end, node*2 + 1);
        Node this_node;
        
        this_node.min = min(left.min, right.min);
        this_node.max = max(left.max, right.max);
        stree[node] = this_node;
        return this_node;
    }
}

void getInput() {
    cin >> N >> M;
    org.assign(N, 0);
    stree.assign(4*N, {0,0});
    for(int i=0; i<N; i++) {
        cin >> org[i];
    }

    initTree(0, N-1, 1);
}

Node getMinMax(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return {INT_MIN,INT_MAX};
    if(start == end) return stree[node];
    if(left <= start && end <= right) return stree[node];
    else {
        int mid = (start + end) / 2;
        Node left_node = getMinMax(start, mid, node*2, left, right);
        Node right_node = getMinMax(mid+1, end, node*2 + 1, left, right);
        Node this_node;
        this_node.min = min(left_node.min, right_node.min);
        this_node.max = max(left_node.max, right_node.max);
        
        return this_node;
    }
}

void solution() {
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        Node found = getMinMax(0, N-1, 1, a-1, b-1);
        cout << found.min << " " << found.max << "\n";
    }
}

int main() {
    cin.tie(NULL);
    getInput();
    solution();
}