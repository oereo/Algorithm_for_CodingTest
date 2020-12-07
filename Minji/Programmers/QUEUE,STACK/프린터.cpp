#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	// 큐에 인덱스 저장
	queue<int> q;
	int len = priorities.size();
	for(int i = 0; i < len; i++) {
		q.push(i);
	}
    
	// 우선순위에 따라 인쇄 수행
	int answer = 0;
	int MAX = *max_element(priorities.begin(), priorities.end());
	int now;
	while(1){
		now = q.front();
		if(priorities[now] == MAX){
			answer++;
			priorities[now] = 0;
			MAX = *max_element(priorities.begin(), priorities.end());
            
			if(now == location)
				return answer;
			else
				q.pop();
		}
		else {
			q.push(now);
			q.pop();
		}
	}
}