#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> days(n);
    for(int i = 0; i < n; i++) {
        days[i] = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            days[i]++;
    }
    
    vector<int> answer;
    int count = 1;
    int max = days[0];
    for(int i = 1; i < n; i++) {
        if(max >= days[i])
            count++;
        else{
            max = days[i];
            answer.push_back(count);
            count = 1;
        }
    }
    answer.push_back(count);
    
    return answer;
}
