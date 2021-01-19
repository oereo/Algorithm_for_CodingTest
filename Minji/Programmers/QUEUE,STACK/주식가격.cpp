#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    int count = 0;
    vector<int> answer(len);
    for(int i = 0; i < len - 1; i++) {
        for(int j = i+1; j < len; j++) {
            answer[i]++;
            if(prices[i] > prices[j])
                break;
        }
    }
    return answer;
}
