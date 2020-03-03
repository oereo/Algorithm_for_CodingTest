#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<pair<int,int>> v;
    int len = priorities.size();
    for(int i = 0; i < len; i++) {
    	v.push_back({priorities[i],i});
	}
	int index = 0;
    int answer = 0;
	while(1){
		if(v[index%len].first == *max_element(priorities.begin(), priorities.end())){
			answer++;
            priorities[index%len] = 0;
            if(v[index%len].second == location)
                return answer;
		}
        index++;
	}
	return 0;
}
