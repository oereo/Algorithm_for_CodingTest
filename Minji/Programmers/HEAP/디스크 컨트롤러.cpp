#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

struct cmp{ // 소요시간이 짧은 것부터 (Min heap)
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    int len = jobs.size();
    int flag = 0;
    int time = 0;
    int answer = 0;
    while(flag < len || !pq.empty()){
        for(int i = flag; i < len; i++){
            if(jobs[i][0] > time)
                break;
            pq.push({jobs[i][0], jobs[i][1]});
            flag++;
        }
        if(flag < len && pq.empty()){
            time++;
            continue;
        }
        int first = pq.top().first;
        int second = pq.top().second;
        answer += second + time - first;
        time += second;
        pq.pop();
    }
    return answer/len;
}
