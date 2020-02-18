#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> budgets, int M) {
    int max = *max_element(budgets.begin(), budgets.end());
    long sum = 0;
    for(int i : budgets)
        sum += i;
    if(sum <= M)
        return max;
    
    int n = budgets.size();
    int start = 0;
    int end = max;
    int mid;
    int answer = 0;
    while(end - start >= 0) {
        mid = (start + end) / 2;
        long total = 0;
        for(int i : budgets){
            if(i > mid)
                i = mid;
            total += i;            
        }
        
        if(total == M)
            return mid;
        else if(total < M){
            answer = mid;
            start = mid + 1;
        } else if(total > M)
            end = mid - 1;
    }
    return answer;
}
