#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int n = heights.size();
    vector<int> answer(n);
    for(int i = n - 1; i > 0; i--) {
        for(int j = i-1; j >= 0; j--){
            if(heights[i] < heights[j]){
                answer[i] = j + 1;
                break;
            }
        }
    }
    return answer;
}
