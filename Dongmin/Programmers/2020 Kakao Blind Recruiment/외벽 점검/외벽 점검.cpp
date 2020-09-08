#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int m,k;
map<int, int> weak_searching;
vector<int> covered;
int cover_num = 0;

void dfs(int n, vector<int>& dist, vector<int>& weak, int idx, int friend_num, int& min) {
    if(friend_num == k) {
        return;
    }

    int break_point = weak[idx]+dist[friend_num]+1;
    for(int i=weak[idx]; i<=weak[idx]+dist[friend_num]; i++) {
        int cover_point = i>=n?i-n:i;
        if(covered[cover_point] == 0) {
            covered[cover_point] += 1;
            if(weak_searching.count(cover_point)) cover_num += 1;
        }
        else {
            break_point = i;
            break;
        }
    }

    if(cover_num == m) {
        if(min>friend_num+1) {
            min = friend_num+1;
        }
    }
    else {
        for(int i=0; i<m; i++) {
            if(covered[weak[i]]) continue;
            dfs(n, dist, weak, i, friend_num+1, min);
        }
    }

    for(int i=weak[idx]; i<break_point; i++) {
        int cover_point = i>=n?i-n:i;
        covered[cover_point] -= 1;
        if(weak_searching.count(cover_point)) {
            cover_num -= 1;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 200;
    m=weak.size(), k=dist.size();
    covered.assign(n, 0);
    sort(dist.begin(), dist.end(), greater<int>());
    for(int i=0; i<m; i++) {
        weak_searching[weak[i]] = i;
    }
    
    for(int i=0; i<m; i++) {
        dfs(n, dist, weak, i, 0, answer);
    }
    if(answer == 200) answer = -1;
    return answer;
}