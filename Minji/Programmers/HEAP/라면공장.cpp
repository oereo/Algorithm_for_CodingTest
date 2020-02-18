#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int> pq;
    int j = 0;
    int len = dates.size();
    int answer = 0;
    for(int i = 1 ; i < k ; i++) {
        stock--;
        if(j < len && dates[j] == i){
            pq.push(supplies[j]);
            j++;
        }
        if(stock == 0){
            stock = pq.top();
            pq.pop();
            answer++;
        }
    }
    return answer;
}
