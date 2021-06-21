#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Item {
    int w,v;
    Item() {w=0; v=0;}
};

int dp[101][100001];

int solve(int n, int w, vector<Item> items) {
    if (w < 0) return -1;
    if (n==0 || w==0) return 0;

    int& ret = dp[n][w];
    if (ret != -1) return ret;

    Item it = items.back();
    items.pop_back();
    
    int included = solve(n-1, w-it.w, items);
    ret = max(included<0 ? 0 : it.v + included, solve(n-1, w, items));
    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    vector<Item> items(N, Item());
    for (int i=0; i<N; i++) {
        int W, V;
        cin >> W >> V;
        items[i].w = W;
        items[i].v = V;
    }

    cout << solve(N, K, items) << endl;

    return 0;
}