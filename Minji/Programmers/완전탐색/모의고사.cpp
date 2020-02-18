#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int pattern1[] = {1,2,3,4,5};
    int pattern2[] = {2,1,2,3,2,4,2,5};
    int pattern3[] = {3,3,1,1,2,2,4,4,5,5};
    int score[] = {0,0,0};
    for(int i = 0; i < answers.size(); i++){
        if(pattern1[i%5] == answers[i])
            score[0]++;
        if(pattern2[i%8] == answers[i])
            score[1]++;
        if(pattern3[i%10] == answers[i])
            score[2]++;
    }
    for(int i = 0; i < 3; i++){
        if(score[i] == *max_element(score,score+3))
            answer.push_back(i+1);
    }
    
    return answer;
}
