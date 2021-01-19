#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> answer;
    set<int> result;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            result.insert(numbers[i] + numbers[j]);
        }
    }
    for(int r : result){
        answer.push_back(r);
    }
    return answer;
}