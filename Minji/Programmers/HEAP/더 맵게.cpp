#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i: scoville)
        pq.push(i);
    while(true) {
        if(pq.top() >= K)
            return answer;
        if(pq.size() == 1)
            return -1;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b*2);
        answer++;
    }
}
