#include <bits/stdc++.h>
using namespace std;
struct Pillar {
    int pos;
    int height;
};

bool operator<(const Pillar u, const Pillar v) {
    return u.pos < v.pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Pillar> pillars(N, {0,0});
    for (int i = 0; i < N; i++) {
        cin >> pillars[i].pos;
        cin >> pillars[i].height;
    }
    
    sort(pillars.begin(), pillars.end());
    
    int len = pillars.size();
    int sections = pillars[len-1].pos - pillars[0].pos + 1;

    vector<int> left(sections, 0);
    vector<int> right(sections, 0);

    for (int i=pillars[0].pos, j=0; i<=pillars[len-1].pos && j<N; i++) {
        if (pillars[j].pos == i) {
            left[i-pillars[0].pos] = pillars[j].height;
            right[i-pillars[0].pos] = pillars[j].height;
            j++;
        }
    }

    for (int i = 1; i < sections; i++) {
        left[i] = max(left[i-1], left[i]);
    }
    for (int i = sections - 2; i >= 0; i--) {
        right[i] = max(right[i+1], right[i]);
    }
    
    int maxHeight = *max_element(left.begin(), left.end());
    int minIdx = 10001, maxIdx = -1;
    for (int i = 0; i < sections; i++) {
        if (right[i] == maxHeight && left[i] == maxHeight) {
            minIdx = min(i, minIdx);
            maxIdx = max(i, maxIdx);
        }
    }

    int sum = 0;
    for (int i = 0; i < sections; i++) {
        if (i < minIdx) sum += left[i];
        else if (i >= minIdx && i <= maxIdx) sum += maxHeight;
        else sum += right[i]; 
    }

    cout << sum << '\n';
    return 0;
}
