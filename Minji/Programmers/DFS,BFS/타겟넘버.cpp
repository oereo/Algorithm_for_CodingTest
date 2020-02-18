#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> answer_list(1);
    for(int i : numbers){
        vector<int> temp;
        for(int j : answer_list){
            temp.push_back(j+i);
            temp.push_back(j-i);
        }
        answer_list = temp;
    }
    for(int i : answer_list) {
        if(i == target)
            answer++;
    }
    return answer;
}
