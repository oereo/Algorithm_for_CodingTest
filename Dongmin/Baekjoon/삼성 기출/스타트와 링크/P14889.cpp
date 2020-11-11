#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
vector<vector<int> > synergy;
vector<int> start, link;

void getInput() {
    cin >> N;
    synergy.assign(N, vector<int>(N, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> synergy[i][j];
        }
    }
}

void makeTeam(int remained_start, int remained_link, int total_remained, int& min_diff) {
    if(total_remained == 0) {
        int start_sum = 0, link_sum = 0;

        for(int i=0; i<N/2; i++) {
            for(int j=i+1; j<N/2; j++) {
                int start_first = start[i], start_second = start[j];
                int link_first = link[i], link_second = link[j];
                start_sum += synergy[start_first][start_second];
                start_sum += synergy[start_second][start_first];
                link_sum += synergy[link_first][link_second];
                link_sum += synergy[link_second][link_first];
            }
        }

        int diff = abs(start_sum - link_sum);
        if(min_diff > diff) min_diff = diff;
    }
    else {
        int player = N - total_remained;
        if(remained_start > 0) {
            start.push_back(player);
            makeTeam(remained_start-1, remained_link, total_remained-1, min_diff);
            start.pop_back();
        }

        if(remained_link > 0) {
            link.push_back(player);
            makeTeam(remained_start, remained_link-1, total_remained-1, min_diff);
            link.pop_back();
        }
    }
}

void solution() {
    int ans = 99999;
    makeTeam(N/2, N/2, N, ans);
    printf("%d", ans);
}

int main() {
    getInput();
    solution();
}