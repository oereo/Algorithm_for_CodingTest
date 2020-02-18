#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> time;
    queue<int> going;
    int n = truck_weights.size();
    int total = 0;
    int count = 0;
    while(true){
        answer++;
        
        if(total + truck_weights[count] <= weight && n > count){
            going.push(truck_weights[count]);
            time.push_back(bridge_length);
            total += truck_weights[count];
            count++;
        }
        
        if(!time.empty() && *max_element(time.begin(),time.end()) <= 0)
            return answer;
        
        for(int i = 0; i < time.size(); i++){
            time[i]--;
            
            if(time[i] == 0){
                total -= going.front();
                going.pop();
            }
        }
    }
    return answer;
}
